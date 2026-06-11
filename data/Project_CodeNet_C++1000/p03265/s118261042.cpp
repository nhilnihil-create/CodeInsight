#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
#define pff(a,b) printf("%d  %d\n",a,b);
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int dx = x2 - x1;
	int dy = y2 - y1;

	int x3 = x2 - dy;
	int y3 = y2 + dx;

	int x4 = x3 - dx;
	int y4 = y3 - dy;

	printf("%d %d %d %d\n", x3, y3, x4, y4);
	

	return 0;
}