#include <bits/stdc++.h>

#define debug_input freopen("stdin.in", "r", stdin)
#define debug_output freopen("stdout.out", "w", stdout)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORALL(i, n) for(int i = 0; i < n; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())
#define NP(a) next_permutation(a.begin(), a.end())
#define ALL(a) a.begin, a.end()
#define mp make_pair
#define pb push_back
#define endl "\n"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int s = (a + b + c) / 2;
	cout << (int) sqrt(s * (s - a) * (s - b) * (s - c)) << endl;
	return 0;
}