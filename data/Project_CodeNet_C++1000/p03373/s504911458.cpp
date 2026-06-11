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
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    vector<int> p(3), need(2);
    cin >> p[0] >> p[1] >> p[2] >> need[0] >> need[1];
    p[2] = min(p[2] * 2, p[0] + p[1]);
    if (need[0] > need[1]){
        swap(need[0], need[1]);
        swap(p[0], p[1]);
    }
    int res = p[2] * need[0];
    res += (need[1] - need[0]) * min(p[1], p[2]);
    cout << res << '\n';
}
