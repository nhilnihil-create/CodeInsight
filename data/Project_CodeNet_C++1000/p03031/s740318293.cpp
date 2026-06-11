#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > ss;
    rep(i, m) {
        int k;
        cin >> k;
        vector<int> s(k);
        rep(j, k) cin >> s[j];
        ss.push_back(s);
    }

    vector<int> p(m);
    rep(i, m) cin >> p[i];

    ll ans = 0;    
    rep(pat, 1 << n) {
        bool ok = true;
        rep (i, m) {
            auto& s = ss[i];
            int cnt = 0;
            rep(j, s.size()) {
                // s[j]のスイッチがついていたら
                if ((pat >> (s[j] -  1) ) & 1) {
                    cnt++;
                }
            }
           // cout << pat << " " << i << " " << cnt << endl;
            if (cnt % 2 != p[i] ) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans ++;
        }
    }

    put(ans);

    return 0;
}