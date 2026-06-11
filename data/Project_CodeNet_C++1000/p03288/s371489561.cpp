#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
	int r;
	cin >> r;
	if (r >= 2800) cout << "AGC" << endl;
	else if (r >= 1200) cout << "ARC" << endl;
	else cout << "ABC" << endl;

}