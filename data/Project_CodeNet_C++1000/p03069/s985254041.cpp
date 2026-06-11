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
	string s;cin>>s;
	vi f(n,0),b(n,0);
	rep(i,n){
		if(i!=0)f[i]+=f[i-1];
		if(s[i]=='#'){
			f[i+1]++;
		}
	}
	reverse(been(s));
	rep(i,n){
		if(i!=0)b[i]+=b[i-1];
		if(s[i]=='.'){
			b[i+1]++;
		}
	}
	reverse(been(b));
	int ans =INF;
	rep(i,n){
		ans=min(ans,f[i]+b[i]);
	}
	cout<<ans<<endl;
}