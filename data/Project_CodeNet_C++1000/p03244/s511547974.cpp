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
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    // 奇数

    typedef std::pair<int, int> pair;
    vector<vector<pair> > change(2, vector<pair>());

    rep (_n, 2) {
        unordered_map<int, int> c;
        int total = 0;
        for (int i = _n; i < n; i += 2) {
            c[v[i]] = 0;
            total++;
        }
        for (int i = _n; i < n; i += 2) c[v[i]]++;

        for (auto kv: c) {
            change[_n].push_back(pair(kv.first, total - kv.second));
        }
        change[_n].push_back(pair(-1, total));
    }

    rep (i, 2) {
        sort(all(change[i]), [](const pair& lhs, const pair& rhs) {
            return lhs.second < rhs.second;
        });
    }

    int sum = change[0][0].second + change[1][0].second;
    if (change[0][0].first == change[1][0].first) {
        sum = min(
            change[0][0].second + change[1][1].second,
            change[0][1].second + change[1][0].second
        );
    }

    put(sum);

    return 0;
}