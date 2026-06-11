#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef vector<ll> vel;
typedef vector<str> ves;
#define REP(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define rep(i, b) REP(i, 0, b)
const ll mod = 1000000007;
const double pi = 3.14159265358979;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    vel P(N);
    rep(i, N) {
        cin >> P[i];
    }
    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
    rep(i, N) {
        if (P[i] <= A) {
            cnt1++;
        }
        else if (A < P[i] && P[i] <= B) {
            cnt2++;
        }
        else {
            cnt3++;
        }
    }
    ll ans = min(cnt1, min(cnt2, cnt3));
    cout << ans << endl;
}