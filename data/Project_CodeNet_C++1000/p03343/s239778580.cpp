#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

typedef pair<int,int> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k,q;
    cin>>n>>k>>q;

    vector<intpair> myVec;

    ll x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	myVec.push_back({x,i});
    }

    sort(myVec.begin(), myVec.end());

    int ans=INT_MAX;
    for(int i=0;i<n;i++){
    	set<ll> indexesToAvoid;
    	ordered_set taken;

    	for(int j=0;j<i;j++){
    		indexesToAvoid.insert(myVec[j].second);
    	}
    	// cerr<<i<<" "<<indexesToAvoid.size()<<endl;

    	int currPointer=i;
    	int mymax=myVec[currPointer].first;
    	int mymin=INT_MAX;

    	int takenCount=0;
    	while(currPointer<n && takenCount<q){
    		int currIndex = myVec[currPointer].second;
    		auto nextOne = indexesToAvoid.upper_bound(currIndex);

    		auto prevOne = nextOne;
    		if(indexesToAvoid.size()>0){
    			prevOne=prev(prevOne);
    		}

    		int nextInd,prevInd;
    		if(nextOne == indexesToAvoid.end()){
    			nextInd = n;
    		}
    		else{
    			nextInd = *nextOne;
    		}

    		if(nextOne == indexesToAvoid.begin() || indexesToAvoid.size()==0){
    			prevInd=-1;
    		}
    		else{
    			prevInd = *prevOne;
    		}

    		// currIndex-=taken.order_of_key(currIndex);
    		nextInd-=taken.order_of_key(nextInd);
    		prevInd-=taken.order_of_key(prevInd);

    		// cerr<<nextInd<<" "<<prevInd<<endl;
    		// if(i==5){
    		// 	cerr<<nextInd<<" "<<prevInd<<" "<<indexesToAvoid.size()<<endl;
    		// }
    		if(nextInd-prevInd-1 >= k){
    			takenCount++;
    			taken.insert(currIndex);
    			mymax=myVec[currPointer].first;
    			mymin=min(mymin,myVec[currPointer].first);
    		}
    		currPointer++;
    	}


    	if(takenCount==q){
    		// cerr<<i<<" "<<mymax<<" "<<mymin<<" "<<mymax-mymin<<" "<<endl;
    		ans=min(ans,mymax-mymin);
    	}
    	else{
    		break;
    	}
    }
    cout<<ans<<endl;

}
