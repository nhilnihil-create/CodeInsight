#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
#define pff(a,b) printf("%d  %d\n",a,b);
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	int b[20];
	rep(i, m) cin >> b[i];
	int a[20][20];
	rep(i, n)rep(j, m) cin >> a[i][j];

	int cnt = 0;
	rep(i, n) {
		int num = 0;
		rep(i2, m) {
			num += a[i][i2] * b[i2];
		}
		num += c;
		if (num > 0) cnt++;
	}
	pf(cnt);

	return 0;
}