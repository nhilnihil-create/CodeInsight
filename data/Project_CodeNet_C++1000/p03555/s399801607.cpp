#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	string s1;
	string s2;
	cin >> s1 >> s2;
	reverse(s2.begin(), s2.end());
	if (s1 == s2) cout << "YES" << endl;
	else cout << "NO" << endl;
}
