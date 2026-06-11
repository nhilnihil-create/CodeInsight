#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task ""

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int N, a[maxn], b[maxn];

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> N;
    for (int i=1; i<=N; ++i){
        cin >> a[i];
    }
    for (int i=1; i<=N; ++i){
        cin >> b[i];
    }
    int res = 0;
    for (int bit=0; bit<=28; ++bit){
        vector<int> va, vb;
        int need = (1 << bit);
        for (int i=1; i<=N; ++i){
            va.pb(a[i] % (2 * need));
            vb.pb(b[i] % (2 * need));
        }
        sort(vb.begin(), vb.end());
        int solan = 0;
        for (auto it : va){
            int l = lower_bound(vb.begin(), vb.end(), need - it) - vb.begin();
            int r = lower_bound(vb.begin(), vb.end(), 2 * need - it) - vb.begin();
            solan += r - l;
            l = lower_bound(vb.begin(), vb.end(), 3 * need - it) - vb.begin();
            r = lower_bound(vb.begin(), vb.end(), 4 * need - it) - vb.begin();
            solan += r - l;
        }
        if (solan & 1)
            res += need;
    }
    cout << res << '\n';
}
