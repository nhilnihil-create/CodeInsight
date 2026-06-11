#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	char x, y;
	cin >> x >> y;
	int a = x - y;
	if (a < 0)cout << "<" << endl;
	else if (a > 0)cout << ">" << endl;
	else cout << "=" << endl;
}