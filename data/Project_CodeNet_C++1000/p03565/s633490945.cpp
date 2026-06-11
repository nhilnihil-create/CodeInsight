#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	string s, t;
	cin >> s;
	cin >> t;
	int n = s.size();
	int m = t.size();
	char c = t[0];
	for (int i = n-1 - (m-1); i >= 0; i--) {
		if (s[i] == c || s[i] == '?') {
			bool b = true;
			for (int j = 0; j < m; j++) {
				if (s[i + j] != t[j] && s[i + j] != '?') b = false;
			}

			if (b) {
				string ans = "";
				for (int j = 0; j < i; j++) {
					if (s[j] == '?') ans += 'a';
					else ans += s[j];
				}
				ans += t;
				for (int j = i + m; j < n; j++) {
					if (s[j] == '?') ans += 'a';
					else ans += s[j];
				}
				cout << ans << endl;
				return 0;
			}
		}
	}
	cout << "UNRESTORABLE" << endl;
}