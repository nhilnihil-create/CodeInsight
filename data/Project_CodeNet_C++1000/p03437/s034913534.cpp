#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task ""

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

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
    int x, y;
    cin >> x >> y;
    if (x % y == 0){
        cout << -1;
        return 0;
    }
    cout << x;
}
