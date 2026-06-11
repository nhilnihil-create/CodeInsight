#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
const long long MOD = 1e9 + 7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}



signed main(){
	int N;
	cin >> N;
	string s;
	cout << 0 << endl;
	flush(cout);
	cin >> s;
	if(s == "Vacant")return 0;
	int l = 0, r = N;
	while(r - l > 1){
		int c = (l + r) / 2;
		string t;
		cout << c << endl;
		flush(cout);
		cin >> t;
		if(t == "Vacant")return 0;
		if((s != t) ^ (c % 2)) r = c;
		else l = c;
	}
}
