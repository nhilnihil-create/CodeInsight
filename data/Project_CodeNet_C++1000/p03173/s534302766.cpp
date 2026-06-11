#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;

const ll mod=1e9+7;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define rc(x)  return cout<<x<<"\n",0
#define sz(s)  (int) s.size()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;

ll t;
const int nax = 405;
const ll INF = 1e18;
ll dp[nax][nax];
int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<int>a(n+1);
	for(ll i=0;i<n;i++)cin>>a[i];
	for (int L = n-1; L>=0; L--) {
		for (int R=L; R<n; R++) {
			if (L==R) {
				dp[L][R] = 0;
			}
			else {
				dp[L][R]=INF;
				ll sum=0;
				for(ll i=L;i<=R;i++)sum+=a[i];
				for (int i=L; i<=R-1; i++) {
					dp[L][R]=min(dp[L][R], dp[L][i] + dp[i+1][R] + sum);
				}
			}
		}
	}
	 printf("%lld\n", dp[0][n-1]);
}
