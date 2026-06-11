#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

ll a[10010], b[10010];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll A = 0, B = 0, diff1 = 0, diff2 = 0;
    rep(i, n){
        A += a[i];
        B += b[i];
        diff1 += max((b[i] - a[i] + 1)/2, 0ll);
        diff2 += max(a[i] - b[i], 0ll);
    }
    ll cnt = B - A;
    bool flag = true;
    
    if (cnt < 0) flag = false;
    else if (cnt < max(diff1, diff2)) flag = false;
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}