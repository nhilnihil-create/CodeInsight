#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);

int main(){
	int n,m;cin>>n>>m;
	ll x[n],y[n],z[n];
	rep(i,n)cin>>x[i]>>y[i]>>z[i];
	ll ans =-INFL;
	rep(a,2)rep(b,2)rep(c,2){
		vl su(n,0);
		rep(i,n){
			if(a==0)su[i]+=x[i];
			else su[i]-=x[i];
			if(b==0)su[i]+=y[i];
			else su[i]-=y[i];
			if(c==0)su[i]+=z[i];
			else su[i]-=z[i];
		}
		ll res =0;
		sort(been(su),greater<ll>());
		rep(i,m)res+=su[i];
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}