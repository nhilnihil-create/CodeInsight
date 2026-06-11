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
    int n, m; cin >> n >> m;
    map<ll, ll> M;
    rep(i, n){
        int a; cin >> a;
        M[-a]++;
    }
    rep(i, m){
        int b, c;
        cin >> b >> c;
        M[-c] += b;
    }
    ll ans = 0;
    ll nums = 0;
    auto itr = M.begin();
    while(nums < n){
        ans += -(*itr).first * min(n - nums, (*itr).second);
        nums += (*itr).second;
        itr++;
        }
    cout << ans << endl;
}