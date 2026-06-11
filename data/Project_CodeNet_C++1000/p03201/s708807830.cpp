#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 1e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;
//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int n;
ll a[200010];
map<ll,int> mp;

void input() {
    cin >> n;
    REP(i,n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a,a+n);
}

void solve() {
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!mp.count(a[i])) continue;
        ll k = 2;
        while (k <= a[i]) k *= 2;
        mp[a[i]]--;
        if (mp[a[i]] == 0) {
            mp.erase(a[i]);
        }
        if (mp.count(k - a[i])) {
            ans++;
            mp[k - a[i]]--;
            if (mp[k - a[i]] == 0) mp.erase(k - a[i]);
        }
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]){
    input();
    solve();
    return 0;
}
