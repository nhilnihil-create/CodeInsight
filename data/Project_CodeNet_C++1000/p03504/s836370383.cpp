    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    ll sm[200020];

    void solve() {
        ll n, c;
        cin >> n >> c;
        ll x[n], y[n], z[n], a[200020];
        for(ll i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
        ll cnt = 0;
        for(ll j = 1; j <= c; j++) {
           for(ll i = 0; i < 200020; i++) a[i] = 0;
           for(ll i = 0; i < n; i++) if(z[i] == j) a[2*x[i] - 1]++, a[2*y[i]]--;
           for(ll i = 1; i < 200020; i++) a[i] += a[i-1];
           for(ll i = 0; i < 200020; i++) if(a[i] > 0) cnt = max(cnt, ++sm[i]);
        }
        cout << cnt << endl;
    }

    int main() {
      cin.sync_with_stdio(0); cin.tie(0);
      cin.exceptions(cin.failbit);
      //ll ti;   cin >> ti;  while(ti--)
      solve();
      return 0;
    }
