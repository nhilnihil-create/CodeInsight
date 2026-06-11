#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)
#define MAX_N 10
int main() {
	char s[MAX_N+1]; cin >> s;
	int ans = 0;
	for (int i = 0; i < strlen(s); i++) {
		for (int j = strlen(s)-1; j >= i; j--) {
			for (int k = i; k <= j; k++) {
				if (s[k] != 'A' && s[k] != 'C'
				    && s[k] != 'G' && s[k] != 'T') break;
				if (k == j) ans = max(ans, j-i+1);
			}
		}
	}
	cout << ans << endl;
}