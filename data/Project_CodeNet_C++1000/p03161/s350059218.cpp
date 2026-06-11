#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define gap ' '
#define L(i) ((i) - (&i))

const int MAXN = 1000010;
const int MAX = 1e6 + 1;
const int MOD = 1e9;
const int INF = 1e9;

int main(){	
	int n, k; cin >> n >> k;
	vector<int> a(n,0);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> dp(n,INF);
	dp[0] = 0;
	for(int i = 0; i < n; ++i){
		int e = i+1;
		for(int j = 1; j <= k; ++j){
			if(e < n){
				dp[e] = min(dp[e], dp[i]+abs(a[i]-a[e]));
				e++;
			}
			else
				break;
		}
	}
	cout << dp[n-1] << "\n";
	return 0;
}