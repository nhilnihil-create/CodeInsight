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

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    
    typedef std::pair<int, int> pair;
    vector<pair> p;
    rep(i, n) p.push_back(pair(i, a[i]));
    sort(all(p), [](const pair& lhs, const pair& rhs) {
        return lhs.second < rhs.second;
    });

    ll total = 0;
    rep(i, n) {
        int idx = p[i].first;
        ll ai = a[idx];
        ll bi = b[idx];

        if (m >= bi) {
            total += ai * bi;
            m -= bi;
        }
        else {
            total += ai * m;
            break;
        }
    }

    put(total);

    return 0;
}