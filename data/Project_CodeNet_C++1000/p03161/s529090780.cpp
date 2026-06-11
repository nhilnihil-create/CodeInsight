#include <bits/stdc++.h>

#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back

const int maxm = 1000000000 + 7;

using namespace std;

int in[100007];
long long arr[100007];

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	loop(i, n) {
		cin >> in[i];
	}
	arr[0] = 0;
	arr[1] = abs(in[1] - in[0]);
	for (int j = 2; j < n; j++) {
		arr[j] = numeric_limits<int>::max();
		for (int l = 1; l <= k; l++) {
			if (j - l < 0)
				break;
			arr[j] = min(arr[j - l] + abs(in[j] - in[j - l]), arr[j]);
		}
	}
	cout << arr[n - 1];
}