#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
char s[nmax];
char q[nmax][2];
int n, m, ans1, ans2;


int last_position(int p) {

	if(!(p >= 1 && p <= n))
		return p;

	for(int i = 0; i < m; i++) {
		if(q[i][0] == s[p]) {
			if(q[i][1] == 'L') {
				if (--p == 0)
					return 0;
			}
			else {
				if (++p == n + 1)
					return n + 1;
			}
		}
	}
	return p;
}

int main()
{

	cin >> n >> m;
	cin >> s + 1;
	//cout << s + 1 << '\n';
	for(int i = 0; i < m; i++)
		cin >> q[i][0] >> q[i][1];

	int st = 1, dr = n; ans1 = 0;
	while (st <= dr) {
		int mid = (st + dr) / 2;
		if(last_position(mid) == 0) {
			ans1 = mid;
			st = mid + 1;
		}
		else
			dr = mid - 1;
	}

	st = 1, dr = n; ans2 = n + 1;
	while (st <= dr) {
		int mid = (st + dr) / 2;
		//cout << mid << '\n';
		if(last_position(mid) == n + 1) {
			ans2 = mid;
			dr = mid - 1;
		}
		else
			st = mid + 1;

	} while(st <= dr);

	//for (int i = 1; i <= n; i++)
	//	cout << last_position(i) << '\n';

	//cout << ans1 << '\n';
	//cout << ans2 << '\n';
	cout << ans2 - ans1 - 1 << '\n';
}
