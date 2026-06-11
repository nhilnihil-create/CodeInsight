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
//const int PI = acos(-1);
int main(){
	ll n,m;cin>>n>>m;
	ll sum=0;
	map<ll,ll>mo;
	rep(i,n){
		ll a;
		cin>>a;
		a%=m;
		sum +=a;
		sum%=m;
		mo[sum]++;
	}
	ll ans =0;
	mo[0]++;
	for(auto i  :mo){
		ll sm = i.second;
		ans+=(sm*(sm-1))/2;
	}
	cout<<ans<<endl;
	
}