/*
	author: parv2809
*/

#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define inf 1e18
#define fo(i,y,n,inc)	for(int i=y;i<n+y;i+=inc)
#define cin(t) int t;cin>>t
#define w(t) while(t--)
#define nl cout<<endl;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ft(i) (i&(-1*i))
#define arrIn(arr,size)		for(int i=0;i<size;i++){cin>>arr[i];}
#define arrOut(arr,size,seperater)	for(int i=0;i<size;i++){cout<<arr[i]<<seperater;}
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int powmd(int a, int b) {
	if (b == 1)	return a;
	if (b == 0)	return 1;

	int half = powmd(a, b / 2);
	int ans = half * half;
	ans %= mod;
	if (b & 1) {
		ans *= a;
	}
	ans %= mod;
	return ans;
}

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

struct block {
	int weight, solidness, value;
};

bool custom_compare(block& a, block& b) {
	return (a.weight + a.solidness) > (b.weight + b.solidness);
}

int dp[1005][10005];

void solve(vector<block>& blocks) {

	int n = blocks.size();

	for (int i = 0; i <= 10000; i++) {
		if (blocks[0].solidness >= i)
			dp[0][i] = blocks[0].value;
		else
			dp[0][i] = 0;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 10000; j++) {
			int first = dp[i][j] = dp[i - 1][j];
			int second = 0;
			if (blocks[i].solidness >= j) {
				second = blocks[i].value + ((j + blocks[i].weight > 10000) ? 0 : dp[i - 1][j + blocks[i].weight]);
			}
			dp[i][j] = max(first, second);
		}
	}

}

int32_t main() {

	fastIO();
	int t = 1;
	w(t) {

		int n;
		cin >> n;

		vector<block> blocks(n);

		for (int i = 0; i < n; i++) {
			cin >> blocks[i].weight >> blocks[i].solidness >> blocks[i].value;
		}

		sort(blocks.begin(), blocks.end(), custom_compare);

		solve(blocks);
		cout << dp[n - 1][0];
	}

	return 0;
}

// cout << "Case #" << i << ": " << answer << endl;