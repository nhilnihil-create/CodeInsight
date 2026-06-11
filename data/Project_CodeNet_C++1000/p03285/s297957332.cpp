#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	set<int>a;
	for (int i = 0; i <= 25; i++) {
		for (int j = 0; j <= 15; j++)a.insert(i * 4 + j * 7);
	}
	if (a.count(n))cout << "Yes" << endl;
	else cout << "No" << endl;

}