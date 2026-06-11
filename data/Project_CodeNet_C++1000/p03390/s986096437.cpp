#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main() {
    ios_base::sync_with_stdio(0);


    int q;
    cin >> q;

    while (q--) {
        int a, b;

        cin >> a >> b;

        if (a > b) swap(a, b);

        if (a == b) {
            cout << 2*(a-1) << "\n";
            continue;
        }

        int c = a*b;
        int p = 0;
        int q = 0;

        while (p*p < a) p++;
        while (q*q < b) q++;
        p--; q--;
        int s = p*q;

        s--;

        while (s*s < c) s++;

        s--;

        cout << 2*s - 2 + (s*(s+1) < c) << "\n";
    }


    return 0;
}
