#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = INF;
	int tmp;
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i,n) cin >> a[i];
	int ch[n+1] = {};
	REP1(i,n) ch[a[i-1]] = ch[a[i-1]-1] + 1;
	REP1(i,n) ans = min(ans, n - ch[i]);
	cout << ans << endl;
}
