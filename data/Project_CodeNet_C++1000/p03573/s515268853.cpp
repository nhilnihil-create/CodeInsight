#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin,(a).rend()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ans = a == b ? c : a == c ? b : a;
	printf("%d", ans);
	return 0;
}