#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define leftunique(a) {sort((a).begin(),(a).end());(a).erase(unique((a).begin(),(a).end()),(a).end());}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
static const ll INF = 1LL << 60;
//Write From this Line

int main()
{
	string s;
	cin >> s;
	int k;
	cin >> k;
	map<string,int> my_m;
	int n = s.size();
	string t;
	rep(i,n){
		For(j,1,k+1){
			// i 文字目から j 文字を取る
			if (i + j > s.size()) continue;
			t = s.substr(i,j);
			my_m[t] += 1;
		}
	}
	int count = 1;
	for(auto x:my_m){
		if (count == k){
			cout << x.first << endl;
			return 0;
		}
		count ++ ;
	}
}
