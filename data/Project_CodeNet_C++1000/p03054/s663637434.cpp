#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task "runaway"

using namespace std;
typedef long long ll;

int encode(char x)
{
    if (x == 'D') return 0;
    else if (x == 'U') return 1;
    else if (x == 'L') return 2;
    else return 3;
}

int nencode(char x)
{
    if (x == 'U') return 0;
    else if (x == 'D') return 1;
    else if (x == 'R') return 2;
    else return 3;
}

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
    int H, W, N; cin >> H >> W >> N;
    int nx, ny; cin >> nx >> ny;
    string s, t; cin >> s >> t;
    vector<int> cnt(4), remain(4);
    remain[0] = H - nx + 1;
    remain[1] = nx;
    remain[2] = ny;
    remain[3] = W - ny + 1;
    for (int i=0; i<N; ++i){
        cnt[encode(s[i])]++;
        for (int type=0; type<4; ++type){
            if (cnt[type] >= remain[type]){
                cout << "NO";
                return 0;
            }
        }
        cnt[nencode(t[i])]--;
        cnt[nencode(t[i])] = max(cnt[nencode(t[i])], -remain[encode(t[i])] + 1);
    }
    cout << "YES";
}
