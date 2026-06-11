#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);

int main() {
    ll n, m; cin >> n >> m;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    sort(all(a));
    vector<Pll> x;
    rep(i, m){
        ll b, c;
        cin >> b >> c;
        x.push_back(make_pair(c, b));
    }
    sort(all(x), greater<Pll>());
    vll y;
    ll nums = 0;
    auto itr = x.begin();
    while (nums < n && itr < x.end()){
        ll add = min(n - nums, (*itr).second);
        rep(i, add){
            y.push_back((*itr).first);
        }
        nums += add; 
        advance(itr, 1);
    }
    ll tmp_ans = accumulate(all(a), 0LL);
    ll ans = tmp_ans;
    ll N = min(y.size(), a.size());
    rep(i, N){
        tmp_ans += y[i] - a[i];
        ans = max(ans, tmp_ans);
    }
    cout << ans << endl;

}