#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf (1ll<<60)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll A, B, Q; cin >> A >> B >> Q;
    vll s(A); rep(i, A) cin >> s[i];
    vll t(B); rep(i, B) cin >> t[i];
    vll x(Q); rep(i, Q) cin >> x[i];

    sort(all(s)), sort(all(t));
    s.insert(s.begin(), -inf);
    t.insert(t.begin(), -inf);
    s.push_back(inf);
    t.push_back(inf);

    for (ll pos : x) {
        vll ns(2), nt(2);
        ll left = 0, right = s.size()-1;
        ll mid;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (s[mid] < pos && pos <= s[mid+1]) {
                ns[0] = s[mid], ns[1] = s[mid+1];
                break;
            }

            if (s[mid] < pos) left = mid; else right = mid;
        }
        ns[0] = s[mid], ns[1] = s[mid+1];

        left = 0, right = t.size()-1;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (t[mid] < pos && pos <= t[mid+1]) {
                nt[0] = t[mid], nt[1] = t[mid+1];
                break;
            }

            if (t[mid] < pos) left = mid; else right = mid;
        }
        nt[0] = t[mid], nt[1] = t[mid+1];

        ll minn = inf;
        rep(i, 2) rep(j, 2) minn = min(
            minn,
            abs(ns[i] - pos) + abs(nt[j] - ns[i])
        );

        rep(i, 2) rep(j, 2) minn = min(
            minn,
            abs(nt[i] - pos) + abs(ns[j] - nt[i])
        );
        cout << minn << endl;
    }
    return 0;
}