#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	string a, b, c; cin >> a >> b >> c;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		map<char, int>check;
		check[a[i]]++;
		check[b[i]]++;
		check[c[i]]++;
		int tmp = max({ check[a[i]],check[b[i]],check[c[i]] });

		if (tmp == 3);
		else if (tmp == 2)ans++;
		else if (tmp == 1)ans += 2;
	}
	cout << ans << endl;

	return 0;
}