#include <bits/stdc++.h>

using namespace std;

#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORD(i, m, n) for (int i = m; i >= n; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP1(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string n;
	cin >> n;
	if(n[1]==n[2]){
		if(n[0]==n[1]||n[2]==n[3]){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}