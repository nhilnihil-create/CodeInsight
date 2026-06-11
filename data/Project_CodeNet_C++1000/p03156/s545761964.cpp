#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int p[100];
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	rep(i, n) {
		cin >> p[i];
	}
	rep(i, n) {
		if (p[i] <= a) {
			cnt1++;
		}
		else if (a + 1 <= p[i] && p[i] <= b) {
			cnt2++;
		}
		else if (b + 1 <= p[i]) {
			cnt3++;
		}
	}
	int ans = min(min(cnt1, cnt2), cnt3);
	cout << ans << endl;
	return 0;
}