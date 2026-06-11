#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<int> c(n - 1), s(n - 1), f(n - 1);
    rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];

    vector<int> ans(n, 0);
    rep(k, n - 1) {
        int tot = 0;
        forr(i, k, n - 1) {
            if(tot < s[i]) tot = s[i];
            else if((tot - s[i]) % f[i] != 0) {
                tot = tot + f[i] - tot % f[i];
            }
            tot += c[i];
        }
        ans[k] = tot;
    }

    for(auto x : ans) cout << x << endl;

    return 0;
}