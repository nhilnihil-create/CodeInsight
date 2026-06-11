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
    int cnt[4]={};
    rep(i, 3) {
        int a, b;
        cin >> a >> b;
        cnt[a-1]++;
        cnt[b-1]++;
    }
    bool flag = true;
    rep(i, 4) if (cnt[i] >= 3) flag = false;

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
