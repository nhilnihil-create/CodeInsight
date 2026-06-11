#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a[5], k;
	for (int i = 0; i < 5; ++i) {
		cin >> a[i];
	}
	cin >> k;
	bool flag = false;
	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			if (abs(a[i] - a[j]) > k) {
				//cout << i << " " << j << "\n";
				flag = true;
				break;
			}
		}
	}
	if (!flag) cout << "Yay!\n";
	else cout << ":(\n";
}

