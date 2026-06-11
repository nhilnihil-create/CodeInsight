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

char t[200010];
char d[200010];
int n, q;
string s;

int sim(int idx){
    rep(i, q){
        if (s[idx] == t[i]){
            if (d[i] == 'R') idx++;
            else idx--;
        }
        if (idx == n+1) return n+1;
        else if (idx == 0) return 0;
    }
    return idx;
}

ll binary_search1() {
    ll ng = -1;
    ll ok = n+1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (sim(mid) == n+1) ok = mid;
        else ng = mid;
    }
    return ok;
}

ll binary_search2() {
    ll ng = n+1;
    ll ok = -1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (sim(mid) == 0) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin >> n >> q;
    cin >> s;
    rep(i, q) cin >> t[i] >> d[i];
    s = '?' + s;
    s = s + '?';

    cout << binary_search1() - binary_search2() - 1 << endl;

    return 0;
}
