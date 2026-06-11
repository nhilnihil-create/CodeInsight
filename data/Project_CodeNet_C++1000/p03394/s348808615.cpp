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

int k;

void input() {
    cin >> k;
}

void solve() {
    int n = k;
    if (n == 3) {
        cout << "2 5 63" << endl;
        return;
    }
    queue<int> v[10];
    vector<int> ans;
    ans.pb(2);
    ans.pb(3);
    for (int i = 4; i <= 30000; i++) {
        if (i % 6 == 0) {
            v[6].push(i);
        } else if (i % 4 == 0) {
            v[4].push(i);
        } else if (i % 3 == 0) {
            v[3].push(i);
        } else if (i % 2 == 0) {
            v[2].push(i);
        }
    }
    ans.pb(v[4].front());
    v[4].pop();
    ans.pb(v[3].front());
    v[3].pop();
    n -= 4;
    while (n > 2 && !v[2].empty()) {
        ans.pb(v[2].front());
        ans.pb(v[4].front());
        v[2].pop();
        v[4].pop();
        n -= 2;
    }
    while (n > 2 && !v[3].empty()) {
        ans.pb(v[3].front());
        v[3].pop();
        ans.pb(v[3].front());
        v[3].pop();
        n -= 2;
    }
    while (n > 0 && !v[6].empty()) {
        ans.pb(v[6].front());
        v[6].pop();
        n--;
    }
    REP(i,k) {
        cout << ans[i] << " \n"[i == k - 1];
    }
}

int main(int argc, char *argv[]){
    input();
    solve();
    return 0;
}
