
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int moveX = x2 - x1, moveY = y2 - y1;
	int x3 = x2 - moveY, y3 = y2 + moveX;
	cout << x3 << " ";
	cout << y3 << " ";
	int x4 = x3 - moveX, y4 = y3 - moveY;
	cout << x4 << " " << y4 << endl;
	return 0;
}