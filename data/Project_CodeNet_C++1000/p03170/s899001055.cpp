#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
typedef long long int ll;

int n, k;
int dp[2][100005];
bool find(bool curr, int arr[], int rem) {
	if (rem < 0)
		return curr;
	if (dp[curr][rem] != -1)
		return dp[curr][rem];
	bool ok = false;
	for (int j = 0; j < n; j++) {
		bool flag = find(!curr, arr, rem - arr[j]);
		if (flag == curr) {
			ok = true;
			break;
		}
	}
	if (ok)
		return dp[curr][rem] = curr;
	return dp[curr][rem] = !curr;
}


int main() {
	fastio;

	cin >> n >> k;
	memset(dp, -1, sizeof dp);
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (find(true, arr, k))
		cout << "First";
	else
		cout << "Second";
	return 0;
}