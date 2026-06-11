#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<tuple>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = max(max(10 * a + b + c, 10 * b + a + c), 10 * c + a + b);
	cout << ans << endl;
	return 0;
}