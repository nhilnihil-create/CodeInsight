#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
#define MAX 10000000000
#define rep(i,n) for(int i = 0; i < n;i++)
ll v, n, c, e, u, k, ans = 0;
int main(void) {
	int h, w = 1, a[100];cin >> h;char s[100][100];
	rep(i, h) {
		cin >> a[i];
		if (i != 0) {
			if (a[i] == a[i - 1]) {
				w++;
			}
			else if (w > 0) {
				ans += (w / 2);
				w = 1;
			}
		}
	}
	if (w > 0) ans += (w / 2);
	cout << ans << endl;
}