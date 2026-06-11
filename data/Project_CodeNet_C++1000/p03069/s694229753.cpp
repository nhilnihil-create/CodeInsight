#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define mrep(i,j,n) for(int i = j; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define cer(x) cerr << x <<endl
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(ALL(x), val), x.end())

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll mod = 1e9 + 7;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }

int main()
{
	int n; cin >> n;
	string s; cin >> s;
	vector<int>lb(n + 1, 0);
	vector<int>rw(n + 1, 0);
	reps(i, n)
	{
		lb[i] = s[i-1] == '#' ? lb[i-1] + 1 : lb[i-1];
	}
	rrep(i, n)
	{
		if (i == n-1)rw[i] = s[i] == '.' ? 1 : 0;
		else rw[i] = s[i] == '.' ? rw[i + 1] + 1 : rw[i + 1];
	}
	int ans = n;
	rep(i, n + 1)chmin(ans, lb[i] + rw[i]);
	co(ans);
	return 0;
}
