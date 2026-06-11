#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A+2, 0), t(B+2, 0), X(Q, 0);
    s[A] = -1e18;  s[A+1] = 1e18;
    t[B] = -1e18;  t[B+1] = 1e18;
    for(int i=0; i<A; i++)
        cin >> s[i];
    for(int i=0; i<B; i++)
        cin >> t[i];
    for(int i=0; i<Q; i++)
        cin >> X[i];
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for(ll x : X){
        ll sl = *(lower_bound(s.begin(), s.end(), x) - 1);
        ll sr = *lower_bound(s.begin(), s.end(), x);
        ll tl = *(lower_bound(t.begin(), t.end(), x) - 1);
        ll tr = *lower_bound(t.begin(), t.end(), x);

        // cout << x << " " << sl << " " << sr << " " << tl << " " << tr << endl;

        ll ans = 1e18;
        ans = min(ans, x - min(tl, sl));
        ans = min(ans, max(tr, sr) - x);
        ans = min(ans, (tr - x) + (tr - sl));
        ans = min(ans, (sr - x) + (sr - tl));
        ans = min(ans, (x - tl) + (sr - tl));
        ans = min(ans, (x - sl) + (tr - sl));
        cout << ans << endl;
    }
}
