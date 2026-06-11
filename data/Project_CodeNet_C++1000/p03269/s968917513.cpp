#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define endl '\n'

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;


int main() {

#ifndef ONLINE_JUDGE
    //freopen("in.in", "r", stdin);
    //freopen("in.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<pii, int> > edges, ans;
    int l, sum = 0, mn = 30, st, cur;
    cin >> l;
    int tmp = l;
    l--;
    int base = 0;
    while (base <= l) {
        st = 1, cur = -1, sum = 0;
        for (int i = 21; i >= 2; i--) {
            cur = i;
            sum += st;
            if (base + sum > l) {
                break;
            }
            st <<= 1;
        }
        mn = min(mn, cur);
        edges.push_back({{1, cur}, base});
        base += st;
    }

    st = 1;
    rloop(i, 20) {
        if (i == mn - 1 || i == 1)break;
        edges.pb({{i, i + 1},
                  st});

        edges.pb({{i, i + 1},
                  0});

        st <<= 1;
    }


    vector<int> v;
    for (auto edge : edges)if (edge.fr.fr != mn)v.pb(edge.fr.fr);
    for (auto edge : edges)if (edge.fr.sc != mn)v.pb(edge.fr.sc);
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
    for (auto &edge : edges)edge.fr.fr = upper_bound(ALL(v), edge.fr.fr) - v.begin();
    for (auto &edge : edges)edge.fr.sc = upper_bound(ALL(v), edge.fr.sc) - v.begin();
    for (auto edge : edges)if (edge.fr.fr != edge.fr.sc)ans.pb(edge);
    swap(edges, ans);
    cout << SZ(v) << " " << SZ(edges) << endl;
    for (auto edge : edges)cout << edge.fr.fr << " " << edge.fr.sc << " " << edge.sc << endl;

    return 0;
}