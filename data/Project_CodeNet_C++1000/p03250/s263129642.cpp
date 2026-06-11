#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string a, b, c; cin >> a >> b >> c;
	int x1 = stoi(a + b) + stoi(c);
	int x2 = stoi(b + c) + stoi(a);
	int x3 = stoi(c + a) + stoi(b);
	cout << max({ x1,x2,x3 }) << endl;
	return 0;
}