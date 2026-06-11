#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b; cin >> a >> b;
	bool can = false;
	if (a <= 8 && b <= 8) can = true;
	if (can) cout << "Yay!" << endl;
	else cout << ":(" << endl;
	return 0;
}