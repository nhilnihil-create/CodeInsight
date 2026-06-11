#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
//#define Local
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2005;

int n, k, q;
int a[N];

bool chk(int x) {
    for(int i = 1; i <= n; i++) {
        int Min = a[i];
        int res = 0;
        for(int l = 1, r; l <= n; l = r) {
            r = l;
            if(a[l] < Min) {
                ++r; continue;
            }
            int cnt = 0;
            while(r <= n && a[r] >= Min) {
                if(a[r] <= Min + x) ++cnt;
                ++r;
            }
            if(r - l >= k) res += min(r - l + 1 - k, cnt);
        }
        if(res >= q) return true;
    }
    return false;
}

void run() {
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = 1e9 + 1, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    while(cin >> n >> k >> q) run();
    return 0;
}
