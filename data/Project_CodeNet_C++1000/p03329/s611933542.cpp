#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long inf=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;
#define FORR(x,arr) for(auto& x:arr)
#define ZERO(a) memset(a,0,sizeof(a))





//3111111111111111111111111111111



	void solve(){


		ini(n);
		vi morty;
		morty.push_back(1);
		int tmp = 6;
		while(1){
			morty.push_back(tmp);
			tmp*=6;
			if(tmp>1e5)break;
		}
		tmp = 9;
		while(1){
			morty.push_back(tmp);
			tmp*=9;
			if(tmp>1e5)break;
		}
		vi dp(100007,inf);
		dp[0] = 0;
		FOR(i,0,100000){
			FORR(x,morty){
				if(i+x<=100000)dp[i+x] = min(dp[i+x],dp[i]+1); 
			}
		}
		out(dp[n]);










	}	























int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall 
	oneforall

	solve();
	


	return 0;
}
