#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define cer(x) cerr << x <<endl
#define ALL(a) (a).begin(),(a).end()
#define MOD 1e9+7
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	int n;
	string a, b, c;
	cin >> n >> a >> b >> c;
	int ans = 0;
	rep(i, n)
	{
		set<char> tmp;
		tmp.insert(a[i]);
		tmp.insert(b[i]);
		tmp.insert(c[i]);
		if (tmp.size() == 2)ans++;
		else if (tmp.size() == 3)ans += 2;
	}
	co(ans);
	return 0;
}
