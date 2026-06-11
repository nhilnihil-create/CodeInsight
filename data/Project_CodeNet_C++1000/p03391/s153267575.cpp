#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    ll n, a, b;
    while(cin >> n) {
        ll ans = 0, flag = 2e9;
        for(int i = 0; i < n; i++) {
            scanf("%lld %lld", &a, &b);
            ans += a;
            if(a > b) flag= min(flag, b);
        }
        if(flag == 2e9) cout << 0 << endl;
        else
            cout << ans - flag<< endl;
    }
    return 0;
}
