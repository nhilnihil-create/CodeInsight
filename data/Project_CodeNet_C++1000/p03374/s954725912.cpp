#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define int long long
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;
    vector<int> x(n), v(n);
    REP(i, n){
        cin >> x[i] >> v[i];
    }
    vector<int> r(n), l(n);
    r[0] = v[0] - x[0];
    l[0] = v[n-1] - (c - x[n-1]);
    FOR(i, 1, n){
        r[i] = v[i] - (x[i] - x[i-1]);
        r[i] += r[i-1];
        l[i] = v[n-i-1] - (x[n-i] - x[n-i-1]);
        l[i] += l[i-1];
    }

    vector<int> r_max(n), l_max(n);
    int r_tmp = 0, l_tmp = 0;
    REP(i, n){
        if(r[r_tmp] < r[i]) r_tmp = i;
        r_max[i] = r_tmp;
        if(l[l_tmp] < l[i]) l_tmp = i;
        l_max[i] = l_tmp;
    }

    int ans = 0;
    ans = max(ans, r[r_max[n-1]]);
    ans = max(ans, l[l_max[n-1]]);
    REP(i, n-1){
        int j = n-i-2;
        ans = max(ans, r[r_max[i]] + l[l_max[j]] - min(x[r_max[i]], c-x[n-1-l_max[j]]));
    }

    cout << ans << "\n";
    return 0;
}