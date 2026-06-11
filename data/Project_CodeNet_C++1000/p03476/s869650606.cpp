#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

struct Prime {
    int n;
    vector<int> p;
    vector<bool> is_prime;
    Prime(int n): n(n), is_prime(n+1, true) {
        rep(i, n+1) {
            if (i<=1) {
                is_prime[i] = false;
                continue;
            }
            if (!is_prime[i]) continue;
            for (int j=2*i; j<=n; j+=i) {
                is_prime[j] = false;
            }
        }
        rep(i, n+1) {
            if (is_prime[i]) p.push_back(i);
        }
    }
};
const int MX = 100005;
int main(){
    int q;
    cin >> q;
    Prime pr(MX);
    vector<int> v;
    rep(i, MX) {
        if (i%2==0) continue;
        if (pr.is_prime[i] && pr.is_prime[(i+1)/2]) v.push_back(i);
    }
    rep(qi, q) {
        int l, r;
        cin >> l >> r;
        auto it1 = lower_bound(whole(v), l);
        auto it2 = upper_bound(whole(v), r);
        int ans = it2 - it1;
        cout << ans << endl;
    }
    return 0;
}
