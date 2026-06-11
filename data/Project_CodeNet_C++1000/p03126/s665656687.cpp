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
	int n, m;
	cin >> n >> m;
	map<int, int> foo;
	rep(i, n) {
		int k;
		cin >> k;
		rep(i, k) {
			int a;
			cin >> a;
			foo[a]++;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (foo[i] == n) cnt++;
	}
	pf(cnt);

	return 0;
}