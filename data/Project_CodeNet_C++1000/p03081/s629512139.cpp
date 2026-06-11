#pragma GCC optimize("03")
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long 
#define mod 100003

using namespace std;

int n, q;
char c[200100];
pair<char, char> a[200100];

int check(int pos, int cod) {
    for (int i = 1; i <= q; i++) {
        if (c[pos] != a[i].fi)
            continue;
        
        if (a[i].se == 'L')
            pos--;
        else pos++;

        if (cod == 0 && pos < 1)
            return 1;

        if (cod == 1 && pos > n)
            return 1; 
    }
    return 0;
}

int main() {
    // ifstream cin("tst.in");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 1; i <= q; i++)
        cin >> a[i].fi >> a[i].se;

    int cnt = 0;
    int st = 1, dr = n, mid;
    while (st <= dr) {
        mid = (st + dr) / 2;
        if (check(mid, 0))
            st = mid + 1;
        else dr = mid - 1;
    }

    int left = dr;
    st = 1, dr = n;
    while (st <= dr) {
        mid = (st + dr) / 2;
        if (check(mid, 1))
            dr = mid - 1;
        else st = mid + 1;
    }

    int right = st;

    cout << right - left - 1;

    return 0;
}