#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define mp make_pair
using namespace std;
const int maxn = 2e5 + 5;
typedef pair<int, int> P;
set<P> L, R;
int l[maxn], r[maxn];
int n;
int main() {
#ifdef TT
    freopen("xxx.in", "r", stdin);
#endif // TT
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        L.insert(mp(l[i], i));
        R.insert(mp(r[i], i));
    }
    int now = 0;
    LL ans = 0;
    for(int i = 0; i < n; i += 2) {
        int id = R.begin() -> se;
        L.erase(mp(l[id], id));
        R.erase(mp(r[id], id));
        if(now < l[id]) {
            ans += l[id] - now;
            now = l[id];
        } else if(now > r[id]) {
            ans += now - r[id];
            now = r[id];
        }
        if(i + 1 == n)
            continue;
        id = L.rbegin() -> se;
        L.erase(mp(l[id], id));
        R.erase(mp(r[id], id));
        if(now < l[id]) {
            ans += l[id] - now;
            now = l[id];
        } else if(now > r[id]) {
            ans += now - r[id];
            now = r[id];
        }
    }
    ans += abs(now);
    LL ans1 = 0;
    now = 0;
    for(int i = 0; i < n; ++i){
        L.insert(mp(l[i], i));
        R.insert(mp(r[i], i));
    }
    for(int i = 0; i < n; i += 2) {
        int id = L.rbegin() -> se;
        L.erase(mp(l[id], id));
        R.erase(mp(r[id], id));
        if(now < l[id]) {
            ans1 += l[id] - now;
            now = l[id];
        } else if(now > r[id]) {
            ans1 += now - r[id];
            now = r[id];
        }
        if(i + 1 == n)
            continue;
        id = R.begin() -> se;
        L.erase(mp(l[id], id));
        R.erase(mp(r[id], id));
        if(now < l[id]) {
            ans1 += l[id] - now;
            now = l[id];
        } else if(now > r[id]) {
            ans1 += now - r[id];
            now = r[id];
        }

    }
    ans1 += abs(now);
    cout << max(ans, ans1) << endl;
    return 0;
}
