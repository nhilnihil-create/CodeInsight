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
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	string s;
	cin >> s;
	int n = s.length();
	int ans = INF;
	for (int i = 0; i <= n-3; i++) {
		int x = (s[i] - '0');
		int y = (s[i + 1] - '0');
		int z = (s[i + 2] - '0');
		int a = 100 * x + 10 * y + z;
		ans = min(ans, abs(753 - a));
	}
	cout << ans << endl;

	return 0;
}