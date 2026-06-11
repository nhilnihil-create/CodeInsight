#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int count(int a) {
    int c = 0;
    while (!(a & 1)) {
        a /= 2;
        c++;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        if (!(a & 1)) {
            ans += count(a);
        }
    }
    cout << ans << "\n";
}