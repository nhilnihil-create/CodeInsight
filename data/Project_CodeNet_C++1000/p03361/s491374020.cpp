#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
	//入力
	int h,w;
	cin >> h >> w;
	vector<vector<int>> s(h,vector<int>(w));
	rep(i,h) {
		string s1;
		cin >> s1;
		rep(j,w) {
			if (s1[j]=='#') s[i][j]=1;
		}
	}
	string ans = "Yes";
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] == 1) {
				int okflg = 0;
				if (i > 0) {
					if (s[i - 1][j] == 1) {
						++okflg;
					}
				}
				if (i < h - 1) {
					if (s[i + 1][j] == 1) {
						++okflg;
					}
				}
				if (j > 0) {
					if (s[i][j-1] == 1) {
						++okflg;
					}
				}
				if (j < w - 1) {
					if (s[i][j+1] == 1) {
						++okflg;
					}
				}
				if (okflg == 0) {
					ans = "No";
					goto OWARI;
				}
			}
		}
	}
OWARI:
	//答え
	std::cout << ans << endl;
}
