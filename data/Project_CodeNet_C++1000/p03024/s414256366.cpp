#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
 
//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	REP(i, (int)s.size()) if (s[i] == 'o') ans++;
	if (8 <= 15-(int)s.size() + ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}
