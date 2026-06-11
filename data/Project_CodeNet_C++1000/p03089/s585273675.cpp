#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long INF=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;



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
	


  
  	ini(n);
	vi morty;
	FOR(i,0,n){
		ini(x);
		x--;
		morty.push_back(x);
	}
	int tmp  = n;
	vi rick;
	while(tmp--){
		int tmp1 = -1;
		FOR(i,0,morty.size()){
			if(morty[i] == i)tmp1 = max(tmp1,i);
		}
		if(tmp1 == -1){
			out(-1);
			return 0;
		}
		rick.push_back(tmp1);
		morty.erase(morty.begin()+tmp1);
	}
	for(int i1 = n-1;i1>=0;i1--){
		out(rick[i1]+1);
	}










	return 0;
}
