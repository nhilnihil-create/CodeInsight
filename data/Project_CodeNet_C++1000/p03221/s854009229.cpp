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

    vector<ll> P(m), Y(m);
    rep(i, m) cin >> P[i] >> Y[i];
    
    typedef std::pair<int, int> pair;
    vector<pair> p;
    rep(i, m) p.push_back(pair(i, Y[i]));
    sort(all(p), [](const pair& lhs, const pair& rhs) {
        return lhs.second < rhs.second;
    });

    vector<int> cnt(n);
    vector<int> x(m);
    rep (idx, m) {
        int i = p[idx].first;
        cnt[P[i] - 1]++;
        x[i] = cnt[P[i] - 1];
    }

    rep (i, m) {
        printf("%06Ld%06d\n", P[i], x[i]);
    }

    return 0;
}