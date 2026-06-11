#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define ALL(a) (a).begin(),(a).end()
#define MOD 1e9+7
typedef long long ll;
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + 1 >= c)co(b + c);
	else co(a + 2*b + 1);
	return 0;
}
