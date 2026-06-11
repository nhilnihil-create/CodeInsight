#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define INF9 1000000000 //10^9
#define MOD 1000000007 //10^9+7
#define fi first
#define sc second
using ll=long long;
using pii=pair<ll,ll>;
using vi=vector<int>;

int main() {
    int n; cin >> n;
    double ans = 0;
    rep(i,n) {
        double m; string s; cin >> m >> s;
        ans += s=="JPY"?m:m*380000.0;
    }
    printf("%f\n", ans);
    return 0;
}
