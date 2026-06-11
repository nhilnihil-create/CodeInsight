#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    pii p[N], q[N];
    rep(i, N){
        int a, b;
        cin >> a >> b;
        p[i] = pii(a, b);
    }
    sort(p, p+N);
    rep(i, N){
        int c, d;
        cin >> c >> d;
        q[i] = pii(c, d);
    }
    sort(q, q+N);
    bool used[N];
    fill_n(used, N, false);
    int ans = 0;
    rep(i, N){
        int c = q[i].first, d = q[i].second;
        int k = -1, M = -1;
        rep(j, N){
            int a = p[j].first, b = p[j].second;
            if(!used[j] && a < c && b < d && b > M){
                k = j;
                M = b;
            }
        }
        if(k != -1){
            used[k] = true;
            ans++;
        }
    }
    cout << ans << endl;
}
