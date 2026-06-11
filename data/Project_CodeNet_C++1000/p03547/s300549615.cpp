#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	char x, y;
	cin >> x >> y;
	if (x < y)
		cout << '<' << endl;
	else if (x > y)
		cout << '>' << endl;
	else
		cout << '=' << endl;
}