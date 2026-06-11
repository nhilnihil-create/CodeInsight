#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVS vector<vector<string>>
#define VVC vector<vector<char>>
typedef long long ll;
const int  INF = 2147483647;
const ll INFL = 1LL << 50;
const ll mod = 1000000007;




int main() {
	int n;
	cin >> n;
	VI v(n);
	REP(i, n)cin >> v[i];
	int a = 0;
	REP(i, n)a = max(a, v[i]);
	cout << a << ' ';
	int b = 0;
	REP(i, n) {
		if (abs(a - b * 2) > abs(a - v[i] * 2)) {
			b = v[i];
		}
	}
	cout << b << endl;
	return 0;
}