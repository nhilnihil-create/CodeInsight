#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mem(x, a) memset(x, a, sizeof(x))
#define AC ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int maxn = 2e5 + 50;
int h[maxn], a[maxn], dp[maxn];
set<int> mque;
main(){
	AC;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> h[i];
	for(int i = 1; i <= n; i ++) cin >> a[h[i]];
	mque.insert(0);
	for(int i = 1; i <= n; i ++){
		auto it = prev(mque.upper_bound(h[i]));
		dp[h[i]] = dp[*it ++] + a[h[i]];
		while(it != mque.end() && dp[h[i]] >= dp[*it]){
			it = mque.erase(it);
		}
		mque.insert(h[i]);
	}
	cout << dp[*mque.rbegin()] << "\n";
}