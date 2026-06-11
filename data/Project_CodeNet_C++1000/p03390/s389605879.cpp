#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int main() {
    int q;
    cin >> q;
    while (q--) {
        LL a, b;
        cin >> a >> b;
        LL p = a * b - 1;

        LL x = sqrt((long double)p);

        LL ans = x + p / (x + 1);

        ans -= 1;
        
        if (a == b) {
            ans++;
        }

        cout << ans << endl;;

    }
}
