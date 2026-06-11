#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, h;
	cin >> n >> h;
	vector<int> v(n);
	int maxa = 0;
	for (auto& i : v) {
		int a;
		cin >> a >> i;
		maxa = max(maxa, a);
	}

	sort(v.rbegin(),v.rend());

	int ret = 0;
	for (auto& i : v) {
		if (i <= maxa) {
			break;
		}

		h -= i;
		++ret;

		if (h <= 0) {
			break;
		}
	}

	if (0 < h) {
		ret += h / maxa;
		if (h % maxa != 0) {
			ret++;
		}
	}

	cout << ret << endl;

	return 0;
}