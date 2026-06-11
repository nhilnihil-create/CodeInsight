#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int h, w;
int n;
vector <int> a[MAXN];

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> h >> w;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        a[x].push_back(y);
    }   

    for (int i = 0; i < MAXN; ++i) {
        sort(a[i].begin(), a[i].end());
    }   

    int p = -1;
    for (int i = 0; i < h - 1; ++i) {
        auto t = upper_bound(a[i].begin(), a[i].end(), p);

        p += (t == a[i].end() || *t != p + 1);

        //cout << "FOR " << i << ' ' << p << '\n';

        int pr = upper_bound(a[i + 1].begin(), a[i + 1].end(), p) - a[i + 1].begin();
        --pr;
        if (pr != -1 && a[i + 1][pr] <= p) {
            //cout << "KEK " << i << ' ' << a[i][pr] << '\n';
            cout << i + 1 << '\n';
            exit(0);
        }   
    }   

    cout << h << '\n';
    return 0;
}   