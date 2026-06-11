#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	string a, b;
	cin >> a >> b;

	if (a == b) cout << "=" << endl;
	else if (a > b) cout << ">" << endl;
	else cout << "<" << endl;
}
