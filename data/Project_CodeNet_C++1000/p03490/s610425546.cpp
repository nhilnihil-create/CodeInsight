#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define all(c) begin(c),end(c)
const ll INF = 1e10;
int main() {
	cin.sync_with_stdio(false);
	string s;
	cin >> s;
	int x, y;
	cin >> x >> y;
	int x1 = 0, y1 = 0;
	bool flag = false, f = true;
	int cnt = 0;
	vector<int>tate, yoko;
	s.push_back('T');
	rep(i, s.size()) {
		if (s[i] == 'T') {
			if (f) {
				x -= cnt;
				f = false;
			}
			else if (!flag) yoko.push_back(cnt);
			else tate.push_back(cnt);
			flag = !flag;
			cnt = 0;
		}
		else cnt++;
	}
	sort(tate.begin(), tate.end(), greater<int>());
	sort(yoko.begin(), yoko.end(), greater<int>());

	rep(i, yoko.size()) {
		if (abs(x+yoko[i])>abs(x-yoko[i]))x -= yoko[i];
		else x += yoko[i];
	}
	rep(i, tate.size()) {
		if (abs(y + tate[i])>abs(y - tate[i]))y -= tate[i];
		else y += tate[i];
	}


	if (x == 0&&y == 0) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;

	return 0;
}
