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
#define fore(i,a) for(auto &i:a)
typedef long long ll;
const int  INF = 2147483647;
const ll INFL = 9223372036854775807;
const ll mod = 1000000007;




int main() {
	int n;
	cin >> n;
	VI t(n), v(n);
	REP(i, n)cin >> t[i];
	REP(i, n)cin >> v[i];
	REP(i, n) {
		t[i] *= 2;
		v[i] *= 2;
	}
	VI d(40010, 10000000);
	int s = 0;
	d[0] = 0;
	REP(i, n) {
		d[s] = min(d[s], v[i]);
		REP(j, t[i]) {
			s++;
			d[s] = min(d[s], v[i]);
		}
	}

	d[s] = min(d[s], 0);
	FOR(i, 1, s + 1)d[i] = min(d[i], d[i - 1] + 1);
	for (int i = s - 1; i >= 0; i--)d[i] = min(d[i], d[i + 1] + 1);
	
	double res = 0;
	REP(i, s)res += d[i] + d[i + 1];
	cout <<fixed<<setprecision(10)<< res/8 << endl;
	return 0;
}