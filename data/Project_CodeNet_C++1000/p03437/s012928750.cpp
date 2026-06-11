#include <bits/stdc++.h>

#define ft first
#define sd second
#define sz(x) ((int)x.size())

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double de;









int main() {
	int x, y;
	cin >> x >> y;
	cout << ((x % y)? x: -1);
	return 0;
}