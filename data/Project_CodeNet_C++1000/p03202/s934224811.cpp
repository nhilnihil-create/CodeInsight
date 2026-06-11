#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, top, a[MAXN];
pair <int, int> s[MAXN];
bool check(int p) {
	if (p == 1) {
		bool ans = true;
		for (int i = 1; i <= n; i++)
			ans &= a[i] > a[i - 1];
		return ans;
	}
	top = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= a[i - 1]) {
			while (top >= 1 && s[top].first > a[i]) top--;
			int pos = a[i];
			while (top >= 1) {
				if (s[top].first == pos) {
					s[top].second++;
					if (s[top].second == p) {
						top--;
						pos--;
					} else {
						pos = -1;
						break;
					}
				} else {
					s[++top] = make_pair(pos, 1);
					pos = -1; break;
				}
			}
			if (pos == 0) return false;
			else if (pos != -1) s[++top] = make_pair(pos, 1);
		}
	}
	return true;
}
int main() {
	read(n); int l = 1, r = n;
	for (int i = 1; i <= n; i++)
		read(a[i]);
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}