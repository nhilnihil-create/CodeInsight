#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a+2);
    vector<ll> t(b+2);
    ll m = 100000000000;
    s[0] = -INF + m; s[a+1] = INF - m;
    t[0] = -INF + m; t[b+1] = INF - m;
    for (ll i = 1; i < a+1; i++) {
        cin >> s[i];
    }
    for (ll i = 1; i < b+1; i++) {
        cin >> t[i];
    }

    ll x, ans;
    ll ss, sss, tt, ttt;
    for (ll i = 0; i < q; i++) {
        cin >> x;
        auto itr1 = lower_bound(ALL(s), x);
        auto itr2 = lower_bound(ALL(t), x);
        sss = *itr1;
        itr1--;
        ss = *itr1;
        ttt = *itr2;
        itr2--;
        tt = *itr2;

        ans = INF;
        ans = min(ans, max(sss, ttt) - x);
        ans = min(ans, x - min(ss, tt));
        ans = min(ans, 2 * min(sss - x, x - tt) + max(sss - x, x - tt));
        ans = min(ans, 2 * min(ttt - x, x - ss) + max(ttt - x, x - ss));
        printf("%lld\n", ans);

    }



}