// practice with Dukkha, coached by rainboy
#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	int n; cin >> n;
	long long asum = 0;
	int bmin = INF;
	while (n--) {
		int a, b; cin >> a >> b;
		asum += a;
		if (a > b)
			bmin = min(bmin, b);
	}
	cout << (bmin != INF ? asum - bmin : 0) << '\n';
	return 0;
}
