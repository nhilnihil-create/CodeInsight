#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int, int>;
int main()
{
	int n;
	cin >> n;
	vector<int> b(n), a(n);
	rep(i, n) cin >> b[i];
	bool ok = false;
	int c = 0;
	reverse(b.begin(), b.end());
	rep(i, n) {
		ok = false;
		auto itr = b.begin();
		int c = b.size();
		while (itr != b.end()) {
			if (c == *itr) {
				a[i] = *itr;
				itr = b.erase(itr);
				ok = true;
				break;
			}
			else itr++;
			c--;
		}
		if (!ok) {
			cout << "-1" << endl;
			return 0;
		}
	}
	reverse(a.begin(), a.end());
	rep(i, n) {
		cout << a[i] << endl;
	}
	cout << endl;
	return 0;
}