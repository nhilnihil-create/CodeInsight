#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

int main()
{
    lint n;cin >> n;
    lint ans=0;
    vector<vector<int>> v(2, vector<int>(n));
    REP(j,2)REP(i,n){
        cin >> v[j][i];
    }
    REP(i,n){
        lint x = 0;
        REP(j,i+1){
            x += v[0][j];
        }
        FOR(j,i,n){
            x += v[1][j];
        }
        ans = max(ans, x);
    }
    cout << ans << "\n";
    return 0;
}