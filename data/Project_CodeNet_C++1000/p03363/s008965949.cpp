#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
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
	int n;cin>>n;
	ll a[n];
	rep(i,n)cin>>a[i];
	ll sum[n+1];
	sum[0]=0;
	rep(i,n){
		sum[i+1]=sum[i]+a[i];
	}
	map<ll,ll>m;
	rep(i,n+1){
		m[sum[i]]++;
	}
	ll ans =0;
	for(auto x:m){
		ans+=(x.second*(x.second-1))/2;
	}
	cout<<ans<<endl;
}