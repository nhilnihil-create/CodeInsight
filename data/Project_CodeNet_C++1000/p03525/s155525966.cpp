#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 24;
bool used[N];
int a[N];
int ans = 0;
int n;
void gen(int i) {
    if (i == n) {
        int mn = 24;
        int r = -1;
        for (int i = 0; i < 24; ++i) {
            if (used[i]) {
                if (i)
                    mn = min(mn, i - r);
                r = i;
            }
        }
        mn = min(mn, 24 - r);
        ans = max(ans, mn);
        return;        
    }   
    if (!used[a[i]]) {
        used[a[i]] = 1;
        gen(i + 1);
        used[a[i]] = 0;
    }   
    if (a[i] && !used[24 - a[i]]) {
        used[24 - a[i]] = 1;
        gen(i + 1);
        used[24 - a[i]] = 0;
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    if (n > 24) {
        cout << 0 << endl;
        exit(0);
    }   
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    used[0] = 1;
    gen(0);
    cout << ans << endl;
}   