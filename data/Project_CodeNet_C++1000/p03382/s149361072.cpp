#include <bits/stdc++.h>

#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define ll long long
#define OK puts("OK")
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()

using namespace std;

const int N = 2e5+10;
const int inf = 1e9+7;

int n, a[N], mx, b = inf, d, I;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(mx < a[i]) {
            mx = a[i];
            I = i;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(i == I) continue;
        if(abs(mx / 2 - a[i]) < b) {
            b = abs(mx / 2 - a[i]);
            d = a[i];
        }
        else if(abs(mx / 2 - a[i]) == b) {
            d = max(d, a[i]);
        }
    }
    cout << mx << " " << d << endl;
}
