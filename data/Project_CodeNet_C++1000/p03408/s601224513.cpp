#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    map<string, int> mpa, mpb;
    int n, m;
    cin >> n;
    rep(i, n){
        string s;
        cin >> s;
        mpa[s]++;
    }
    cin >> m;
    rep(i, m){
        string t;
        cin >> t;
        mpb[t]++;
    }

    int ans = 0;
    for(auto e:mpa){
        ans = max(e.second - mpb[e.first], ans);
    }

    cout << ans << endl;

    return 0;
}
