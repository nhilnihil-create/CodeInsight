#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
#include<iomanip>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const ll INF = 1000000007;
double dp[110000];

int main() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	rep(i,n)cin >> a[i];
	dp[0] = 0;
	rep(i, k+1)rep(j, n) {
		if (i == 0)continue;
		if (i - a[j] >= 0 && dp[i - a[j]] == 0)dp[i] = 1;
	}
	if (dp[k])cout << "First";
	else cout << "Second";

	return 0;
}