#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>x(n);
	for (int i = 0; i < n; i++)cin >> x.at(i);

	vector<int>a = x;
	sort(a.begin(), a.end());
	ll amed = a.at((n - 2) / 2 + 1);
	ll amedb = a.at((n - 2) / 2);

	for (int i = 0; i < n; i++) {
		if (x.at(i) < amed)cout << amed << endl;
		else cout << amedb << endl;
	}
}