#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define inf 1e18
#define fo(i,y,n,inc)	for(int i=y;i<n+y;i+=inc)
#define cin(t) int t;cin>>t
#define w(t) while(t--)
#define nl cout<<endl;
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
int n;
vector<int> tree[100005];
int dp[100005][2];

int solve(int currNode, int parent , int prevBlack) {

	if (dp[currNode][prevBlack] != -1)	return dp[currNode][prevBlack];
	int ans = 0;
	int first = 1;
	int second = 1;
	bool leafNode = true;
	for (auto it : tree[currNode]) {
		if (it != parent) {
			leafNode = false;
			second *= solve(it, currNode, 0);
			second %= mod;
			if (!prevBlack) {
				first *= solve(it, currNode, 1);
				first %= mod;
			}
		}
	}
	if (prevBlack == 1) {
		ans = second;
	}
	else ans = first + second;
	ans %= mod;
	return dp[currNode][prevBlack] = ans;
}

int32_t main() {

	fastIO();

	cin >> n;
	fo(i, 0, n - 1, 1) {
		cin(a); cin(b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));

	cout << solve(1, -1, 0) << endl;

	return 0;
}

// cout << "Case #" << i << ": " << answer << endl;