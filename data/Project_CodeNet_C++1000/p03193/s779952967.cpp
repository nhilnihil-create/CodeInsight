#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, h, w, a, b, ans;
int main() {
	cin >> n >> h >> w;
	while(n--) {
		cin >> a >> b;
		ans += (a>=h && b>=w);
	}
	cout << ans;
	return 0;
}