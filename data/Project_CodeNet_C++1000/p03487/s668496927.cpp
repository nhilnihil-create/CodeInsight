#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		
		bool f = true;
		for (int j = 0; j < v.size(); j++) {
			int m = v.at(j).first;
			if (m == n) {
				v.at(j).second++;
				f = false;
				break;
			}
		}

		if (f) {
			pair<int, int> p = { n,1 };
			v.push_back(p);
		}
	}

	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int a, b;
		a = v.at(i).first;
		b = v.at(i).second;

		if (b > a) ans += b - a;
		else if (b < a) ans += b;
	}

	cout << ans << endl;
}