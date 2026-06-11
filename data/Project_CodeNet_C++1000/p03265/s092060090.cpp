#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int dx = x2 - x1;
	int dy = y2 - y1;
	int x3 = x2 - dy;
	int y3 = y2 + dx;
	int x4 = x1 - dy;
	int y4 = y1 + dx;
	cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}