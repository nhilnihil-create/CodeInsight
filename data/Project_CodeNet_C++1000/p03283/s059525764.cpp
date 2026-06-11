#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i,m,n) for(int i = m - 1; i >= n; i--)
#define ALL(v) v.begin(), v.end()
#define itn int
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
template<typename T, typename U>
inline bool CMAX(T m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U>
inline bool CMIN(T m, U x) { if (m > x) { m = x; return true; } return false; }

typedef long long lint;
typedef long double ldouble;
const int INF = 1e9;
const lint LINF = 1e18;
int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n,vector<int>(n,0));
    vector<vector<int>> s(n + 1,vector<int>(n + 1,0));
    vector<int> ans(q);
    REP(i,m){
        int r,l;
        cin >> l >> r;
        l--;r--;
        a[l][r]++;
    }
    FOR(i,1,n+1){
        FOR(j,1,n+1){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }
    REP(i,q){
        int p,q;
        cin >> p >> q;
        ans[i] = s[q][q] - s[q][p - 1] - s[p - 1][q] + s[p - 1][p - 1]; 
    }
    REP(i,q)
        cout << ans[i] << endl;

    return 0;
}
