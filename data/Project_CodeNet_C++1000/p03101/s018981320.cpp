#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	cout << H * W - (h * W + H * w) + h * w << endl;

}