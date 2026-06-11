#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int r,g,b,n; cin >> r>>g>>b>>n;

    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            int s = n - i * r - j * g;
            if(0 <= s && s % b == 0) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
