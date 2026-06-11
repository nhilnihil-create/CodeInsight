#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL<<60;
const ll mod =1000000007;



int main() {

	int n, a, b;
	cin >> n >> a >> b;

	if (a + b > n + 1) {
		cout << -1 << endl;
		return 0;
	}


	VI v;

	int m = n;

	int k = n - a;
	REP(i, a) {
		int x = min(b - 1, k) + 1;
		REP(j, x)v.push_back(m - x + 1+j);
		k -= x - 1;
		m -= x;
	}

	reverse(ALL(v));

	if (v.size() < n) {
		cout << -1 << endl;
		return 0;
	}

	REP(i, n)cout << v[i] << ' ';

	

}