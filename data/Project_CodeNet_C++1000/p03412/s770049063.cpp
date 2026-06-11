#include <bits/stdc++.h>

using namespace std;

#define REP(i,m) for(int i=0; i<m; i++)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define INF 1000000007
#define INFL (1LL << 60)
#define MOD 998244353
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define ll long long int
#define P pair<ll, ll>

int main(){
	int n;
	cin >> n;
	int a[n], b[n];
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i];
	int ans = 0;
	REP(i, 30){
		int am[n], bm[n], bit = 0;
		REP(j, n){
			am[j] = a[j] % (1<<(i+1));
			bm[j] = b[j] % (1<<(i+1));
		}
		sort(bm, bm+n);
		REP(j, n){
			if(am[j] < (1<<i)){
				int x = upper_bound(bm, bm+n, (1<<(i+1))-1-am[j]) - lower_bound(bm, bm+n, (1<<i)-am[j]);
				bit = (x+bit)%2;
			}
			else{
				int x = n - (upper_bound(bm, bm+n, (1<<(i+1))+(1<<i)-1-am[j]) - lower_bound(bm, bm+n, (1<<(i+1))-am[j]));
				bit = (x+bit)%2;
			}
		}
		ans += bit<<i;
	}
	cout << ans << endl;
	return 0;
} 