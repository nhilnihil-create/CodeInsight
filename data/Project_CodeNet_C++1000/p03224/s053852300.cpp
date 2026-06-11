#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define iter(it,a) for(auto it=a.begin();it!=a.end();it++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define preturn(X) cout<<X<<endl; return 0
//cout.setf(ios::fixed); cout.precision(18)
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9+7;

vector<int> ans[1000];

void func(int i,int k,int x){
	if(k==1){
		return;
	}
	rep(j,0,k-1){
		ans[i].pb(x+j);
		ans[i+1+j].pb(x+j);
	}
	func(i+1,k-1,x+k-1);
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    ll k = 1;
    while(k*(k-1) < 2*n){
    	k++;
    }
    if(k*(k-1)==2*n){
    	cout<<"Yes"<<endl;
    	func(0,k,1);
    	cout<<k<<endl;
    	rep(i,0,k){
    		cout<<(k-1)<<" ";
    		iter(it,ans[i]){
    			cout<<(*it)<<" ";
    		}
    		cout<<endl;
    	}
    	return 0;
    }
    preturn("No");
}