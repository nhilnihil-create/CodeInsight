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
	int n;cin>>n;
	string s;cin>>s;
	vi me(26,1);
	rep(i,n){
		me[s[i]-'a']++;
	}
	ll ans =1;
	rep(i,26){
		ans*=max(1,me[i]);
		ans%=mod;
	}
	cout<<ans-1<<endl;
}