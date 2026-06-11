#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <chrono>
#include <queue>
#include <string>
#include <cassert>
#include <bitset>
#include <stack> 
#include <unordered_set>

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 1000000007
#define BASE 77747
#define PI acos(-1.0)
#define MAXLEN 29

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef vector <ll> vll;

struct Block {
	ll w;
	ll s;
	ll v;
};

Block arr[1000];
int n;

bool cmp(Block a, Block b) {
	return a.s + a.w < b.s + b.w;
}
ll dp[1000][10001];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].w >> arr[i].s >> arr[i].v;
	}
	sort(arr, arr + n, cmp);
	ll ans = 0;
	dp[0][arr[0].w] = arr[0].v;
	ans = max(ans, arr[0].w);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 10000; j++) dp[i][j] = dp[i - 1][j];
		for (int j = 0; j <= arr[i].s; j++) {
			ans = max(ans, dp[i - 1][j] + arr[i].v);
			if (j + arr[i].w > 10000) continue;
			dp[i][j + arr[i].w] = max(dp[i][j + arr[i].w], 
				dp[i - 1][j] + arr[i].v);
		}
	}
	cout << ans << endl;
	return 0;
}