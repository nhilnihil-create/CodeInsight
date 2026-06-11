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
	int n;
	cin >> n;
	vector<int> cnt(101, 0);
	for (int i = 1; i <= n; i++) {
		int t = i;
		for (int j = 2; j * j <= t; j++) {
			while (t % j == 0) {
				cnt[j]++;
				t /= j;
			}
		}
		if (t != 1) cnt[t]++;
	}
	int gt5 = 0;
	int gt3 = 0;
	int gt15 = 0;
	int gt25 = 0;
	int gt75 = 0;
	for (int i = 1; i <= 100; i++) {
		if (cnt[i] >= 74) gt75++;
		if (cnt[i] >= 24) gt25++;
		if (cnt[i] >= 14) gt15++;
		if (cnt[i] >= 4) gt5++;
		if (cnt[i] >= 2) gt3++;

	}
	int ans = gt75 + gt25 * (gt3-1) + gt15 * (gt5-1) + gt5*(gt5-1)/2 * (gt3-2);
	ans = max(0, ans);
	cout << ans << endl;
}