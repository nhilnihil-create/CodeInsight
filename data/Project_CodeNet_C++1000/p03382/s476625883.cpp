#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task ""

using namespace std;
typedef long long ll;

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".in", "r")){
        freopen(Task".in", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    int n; cin >> n;
    vector<int> a(n);
    pair<int, int> mx = mp(0, 0);
    for (int i=0; i<n; ++i){
        cin >> a[i];
        mx = max(mx, mp(a[i], i));
    }
    pair<int, int> res = mp(-1e9, 0);
    for (int i=0; i<n; ++i){
        if (i != mx.se) res = max(res, mp(-max(a[i], mx.fi - a[i]), a[i]));
    }
    cout << mx.fi << ' ' << res.se << '\n';
}
