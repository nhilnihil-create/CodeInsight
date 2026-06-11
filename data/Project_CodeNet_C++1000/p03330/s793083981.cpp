#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c,vector<int>(c));
    REP(i,c) REP(j,c) cin >> d[i][j];
    vector<vector<int>> md(3,vector<int>(c));
    REP(i,n) REP(j,n) {
        int x; cin >> x;
        x--;
        REP(k,c) md[(i+j)%3][k] += d[x][k]; 
    }
    
    int ans = 1 << 30;
    REP(i,c) REP(j,c) {
        if (i == j) continue;
        REP(k,c) {
            if (i == k || j == k) continue;
            ans = min(ans,md[0][i]+md[1][j]+ md[2][k]);
        }
    }

    cout << ans << '\n';

    return 0;
}