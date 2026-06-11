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

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}


string s, k;
int dp[3005][3005];

int getLen(int i, int j) {

	if (i >= s.length() || j >= k.length() ) {
		return 0;
	}

	if (dp[i][j] != -1)	return dp[i][j];

	if (s[i] == k[j])		dp[i][j] = 1 + getLen(i + 1, j + 1);

	dp[i][j] = max(dp[i][j], max(getLen(i + 1, j), getLen(i, j + 1)));

	return dp[i][j];
}

string getLcs(int len) {
	string ans = "";
	int i, j;
	i = j = 0;

	while (i < s.length() && j < k.length()) {

		if (s[i] == k[j]) {
			ans += s[i];
			i++; j++;
			len--;
		}
		else {
			if (dp[i][j + 1] > dp[i + 1][j]) {
				j++;
			}
			else {
				i++;
			}
		}
	}

	return ans;

}

void solve() {
	int len = getLen(0, 0);
	cout << getLcs(len);
	nl;

	return;
}

int32_t main() {

	fastIO();

	memset(dp, -1, sizeof(dp));

	cin >> s;
	cin >> k;

	solve();

	return 0;
}

// cout << "Case #" << i << ": " << answer << endl;