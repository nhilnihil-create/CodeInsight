#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define ALL(a) (a).begin(),(a).end()
#define P pair<int, int>
typedef long long ll;
using namespace std;

int main()
{
	int n, a, b; cin >> n >> a >> b;
	int ans_ma = min(a, b);
	int ans_mi = max(a + b - n, 0);
	cout << ans_ma <<" "<< ans_mi << endl;
	return 0;
}