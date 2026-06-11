///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
const int mx = 2000 * 100 + 5;
int ind[mx], dp[mx];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		a--;
		ind[a] = i;
	}
	dp[n - 1] = 1;
	int maxi = 1;
	for(int i = n - 2; i >= 0; i--){
		dp[i] = 1;
		if(ind[i] < ind[i + 1])
			dp[i] += dp[i + 1];
		maxi = max(maxi , dp[i]);
	}
	cout << n - maxi << endl;
	return 0;
}
