#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007



ll n, s[110000], a, b, nm = INF;

int main() {
	cin >> n;
	REP(i, n)cin >> s[i];
	sort(s, s + n, greater<ll>());
	a = s[0];
	REPO(i, n - 1) {
		if (nm > min(abs(a / 2 - s[i]), abs((a + 1) / 2 - s[i]))) {
			nm = min(abs(a / 2 - s[i]), abs((a + 1) / 2 - s[i]));
			b = s[i];
		}
	}
	cout << a << " " << b << endl;
}


