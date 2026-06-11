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
	int a[5];
	rep(i, 5) cin >> a[i];

	int b[5] = { 0 };
	int maxi = 0;
	int mx = 0;
	rep(i, 5) {
		if (a[i] % 10 == 0) continue;
		b[i] = 10 - (a[i] % 10);
		if (mx <= b[i]) {
			maxi = i;
		}
		mx = max(mx, b[i]);
	}
	int time = 0;
	rep(i, 5) {
		if (i == maxi) continue;
		time += a[i];
		if (time % 10 == 0) continue;
		time += 10 - (a[i] % 10);
	}
	time += a[maxi];
	pf(time);

	return 0;
}