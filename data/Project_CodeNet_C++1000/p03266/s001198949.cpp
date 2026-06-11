#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, k; cin >> n >> k;

    ll x = 0, y = 0;
    for(int i = 1; i <= n; i++){
        if(i % k == 0) x++;
        if(i % k == k / 2) y++;
    }

    if(k & 1) cout << x * x * x << endl;
    else cout << x * x * x + y * y * y << endl;

    return 0;
}
