#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	vector<char> c(9);
	rep(i, 9) cin >> c[i]; 
	printf("%c%c%c\n", c[0], c[4], c[8]);
	return 0;
}