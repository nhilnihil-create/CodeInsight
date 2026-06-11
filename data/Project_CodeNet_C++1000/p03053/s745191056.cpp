#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI=3.14159265358979323846;

using namespace std;

int main() {

	int h, w;
	cin >> h >> w;

	char a[h][w];
	queue<pair<int, int>> q;

	int wC = 0;
	int ans = 0;

	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, -1, 1};

	rep (i, h) {
		rep (j, w) {
			cin >> a[i][j];

			if (a[i][j] == '#')
				q.push(make_pair(i, j));
			else 
				wC++;
		}
	}

	while (wC > 0) {

		int size = q.size() + 1 - 1;
	/*	cout << size << endl;
		cout << q.size() << endl;*/

		queue<pair<int, int>> nextQ;

		while (!q.empty()) {
					

			pair<int, int> pos = q.front(); q.pop();
			int x = pos.first;
			int y = pos.second;

			rep(i, 4) {
				int mx = x + dx[i];
				int my = y + dy[i];

				if (mx < 0 || mx >= h || my < 0 || my >= w)
					continue;
					

				//cout << "x = " << x << "  y = " << y << "  mx = " << mx << "  my = " << my << endl;
			

				if (a[mx][my] == '.') {
					nextQ.push(make_pair(mx, my));
					a[mx][my] = '#';
					wC--;
				}
			}
		}
		q.swap(nextQ);
		ans++;
/*
					cout << endl;
		rep (i, h) {
			rep (j, w) {
				cout << a[i][j];
			}
			cout << endl;
		}
		cout << endl;*/
	}

	cout << ans << endl;
}
/*

.Q#QQ#
Q.QQ.Q
#QQ#Q.
QQ.Q..
Q#Q.Q.
.Q.Q#Q*/