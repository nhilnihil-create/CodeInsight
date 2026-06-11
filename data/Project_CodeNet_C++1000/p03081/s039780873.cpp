#include <bits/stdc++.h>

#define ft first
#define sd second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

const int MAXN = 200 * 1000 + 23;





bool check(int);
void inp();
void gedit();

int n, q, ans;
string s;
char save = 'L';
pcc c[MAXN];

int main() {
	inp();
	gedit();
	save = 'R';
	reverse(s.begin(), s.end());
	gedit();
	cout << n - ans;
	return 0;
}
void inp() {
	cin >> n >> q >> s;
	for (int i = 0; i < q; i++)
		cin >> c[i].ft >> c[i].sd;
}
bool check(int v) {
	for (int i = 0; i < q; i++) {
		if (c[i].ft == s[v])
			v = v + ((c[i].sd == save)? -1: 1);
		if (v < 0)
			return true;
	}
	return false;
}
void gedit() {
	int up = n + 1, dw = -1;
	while (up - dw > 1) {
		int m = ((up + dw) >> 1);
		if (check(m))
			dw = m;
		else
			up = m;
	}
	ans += up;
}