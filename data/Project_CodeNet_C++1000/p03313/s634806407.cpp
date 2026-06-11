#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task ""

using namespace std;
typedef long long ll;

const int maxn = 1 << 18;

bool testbit(int x, int n)
{
    return x >> n & 1;
}

int addbit(int x, int n)
{
    return x + (1 << n);
}

pair<int, int> S[maxn];
int a[maxn], N;
ll f[maxn];

void merges(pair<int, int> & a, pair<int, int> b)
{
    if (a.fi < b.fi) a.se = max(a.se, a.fi), a.fi = b.fi;
    else a.se = max(a.se, b.fi);
}

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
    for (int i=0; i<(1<<N); ++i){
        cin >> a[i];
        S[i] = mp(a[i], -1e9);
    }
    for (int j=0; j<N; ++j){
        for (int i=0; i<(1<<N); ++i){
            if (testbit(i, j)){
                int nxt = i - (1 << j);
                merges(S[i], S[nxt]);
            }
        }
    }
    for (int i=0; i<(1<<N); ++i){
        f[i] = S[i].fi + S[i].se;
        f[i] = max(f[i], f[i-1]);
        if (i) cout << f[i] << '\n';
    }
}
