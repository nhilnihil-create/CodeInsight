#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
char str[105];
int main() {
	int n;
	scanf("%d%s", &n, str);
	int r = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		r += str[i] == 'R';
		b += str[i] == 'B';
	}
	printf(r > b ? "Yes\n" : "No\n");
}
