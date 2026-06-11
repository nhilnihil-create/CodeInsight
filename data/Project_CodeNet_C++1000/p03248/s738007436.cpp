#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int n, ck[100009];
string s;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.length();
	if (s[n - 1] == '1') cout << -1 << E;
	else if (s[0] == '0' || s[n - 2] == '0') cout << -1 << E;
	else {
		for (int i = 1; i < n - 2; i++) {
			int t1 = i + 1;
			int t2 = n - t1;
			if (s[i] == '0') {
				if (ck[t1] == 1 || ck[t2] == 1) {
					cout << -1 << E;
					return 0;
				}
				else {
					ck[t1] = -1;
					ck[t2] = -1;
				}
			}
			else {
				if (ck[t1] == -1 || ck[t2] == -1) {
					cout << -1 << E;
					return 0;
				}
				else {
					ck[t1] = 1;
					ck[t2] = 1;
				}
			}
		}
		cout << "1 2" << E;
		int cur = 2, cnt = 2;
		while (1) {
			if (cnt >= n) break;
			if (ck[cnt] == 1) {
				cout << cur << " " << cnt + 1 << E;
				cur = cnt + 1;
			}
			else {
				cout << cur << " " << cnt + 1 << E;
			}
			cnt++;
		}
	}
	//system("pause");
	return 0;
}