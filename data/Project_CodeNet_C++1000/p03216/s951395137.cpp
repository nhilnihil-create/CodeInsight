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

// ref :: https://www.hamayanhamayan.com/entry/2018/11/24/223908

int n, q, k;
string s;

ll solve(int k) {
    ll cnt = 0, ret = 0;
    int c = 0, num_m = 0, num_c = 0;
    rep(a, n) {
        if (s[a] == 'D') {
            while (c < n && c - a < k) { // aを固定して、可能な限りcを伸ばす
                if (s[c] == 'M') num_m++;
                else if (s[c] == 'C') {
                    num_c++;
                    cnt += num_m;
                }
                c++;
            }
            ret += cnt;
        }
        else if (s[a] == 'M') {
            num_m--;
            cnt -= num_c;
        }
        else if (s[a] == 'C') {
            num_c--;
        }
    }
    return ret;
}

int main(){
    cin >> n >> s >> q;

    while(q--) {
        cin >> k;
        cout << solve(k) << endl;
    }    
}
