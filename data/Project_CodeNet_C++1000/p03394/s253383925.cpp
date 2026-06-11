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
		if(n == 3){
			return out(2,3,55);
		}
		else if(n  == 4){
			return out(2,3,9,10);
		}
		else if(n == 5){
			return out(2,3,6,9,10);
		}
		else if(n == 6){
			return out(2,3,9,10,12,24);
		}
		else{
			vi morty;
			int one = 1;
			int tmp = 0;
			while(one){

				FOR(i,0,310000){
					morty.push_back(i*6+2);
					tmp+=i*6+2;
					if(morty.size() == n){one = 0;break;}
					morty.push_back(i*6+3);
					tmp+=i*6+3;
					if(morty.size() == n){one = 0;break;}
					morty.push_back(i*6+4);
					tmp+=i*6+4;
					if(morty.size() == n){one = 0;break;}
					morty.push_back(i*6+6);
					tmp+=i*6+6;
					if(morty.size() == n){one = 0;break;}
				}
			}
			if(tmp%6 == 2){
				morty.erase(find(all(morty),8));
				morty.push_back(30000);
			}
			if(tmp%6 == 3){
				morty.erase(find(all(morty),9));
				morty.push_back(30000);
			}
			if(tmp%6 == 5){
				morty.erase(find(all(morty),9));
				morty.push_back(29998);
			}
			FORR(x,morty)cout<<x<<" ";
			return;
		}
		
		


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
