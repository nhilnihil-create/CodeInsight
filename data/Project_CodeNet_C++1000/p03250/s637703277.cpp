#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string a, b, c; cin >> a >> b >> c;
	int x1 = stoi(a + b) + stoi(c);
	int x2 = stoi(b + a) + stoi(c);
	int x3 = stoi(b + c) + stoi(a);
	int x4 = stoi(c + b) + stoi(a);
	int x5 = stoi(c + a) + stoi(b);
	int x6 = stoi(a + c) + stoi(b);
	cout << max({ x1,x2,x3,x4,x5,x6 }) << endl;
	return 0;
}