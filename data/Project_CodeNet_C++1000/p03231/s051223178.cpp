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
	ll n,k;cin>>n>>k;
	string s,t;cin>>s>>t;
	ll ans = __gcd(n,k);
	ans = (n*k)/ans;
	map<ll,char> res;
	rep(i,n){
		res[i*(ans/n)]=s[i];
	}
	rep(i,k){
		if(res.find(i*(ans/k))!=res.end()&&res[i*(ans/k)]!=t[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
}