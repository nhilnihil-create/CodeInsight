/*Template by hemnath_d(Enlightened by chamow)*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vec vector<ll>
#define pll pair<ll,ll>
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fx first
#define sx second
#define inf 100000000000000
#define minf -100000000000000
#define maxi 100005
struct elem{
	vector<pair<int,int> > val;
	void merge(pair<int,int> x){
		int pos = find(val.begin(),val.end(),x) - val.begin();
		if(pos != val.size())
			return;
		val.pb(x);
		sort(val.begin(),val.end(),greater<pair<int,int> >());
		if(val.size()>2)
			val.resize(2);
	}
};
int main()
{
    fastread;
    int n;
    cin>>n;
    vector<int> arr(1<<n);
    for(int i=0;i<(1<<n);i++){
    	cin>>arr[i];
    }
    vector<elem> mask(1<<n);
    for(int i=0;i<(1<<n);i++)
    	mask[i].merge({arr[i],i});
    for(int i=1;i<(1<<n);i++){
    	for(int j=0;j<n;j++){
    		if(i & (1<<j)){
    			for(int k=0;k<(mask[i^(1<<j)].val.size());k++)
    				mask[i].merge(mask[i^(1<<j)].val[k]);
    		}
    	}
    }
    int ans[(1<<n)];
    for(int i=0;i<(1<<n);i++){
    	ans[i] = mask[i].val[0].fx + mask[i].val[1].fx;
    }
    for(int i=2;i<(1<<n);i++)
    	ans[i] = max(ans[i],ans[i-1]);
    for(int i=1;i<(1<<n);i++)
    	cout<<ans[i]<<endl;
    return 0;
}