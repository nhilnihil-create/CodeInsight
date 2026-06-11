#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int n; cin >> n;
    V<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int sum = pow(3, n);
    int sub = 1;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        if((v[i] - 1) & 1) cnt++;
        if((v[i]) & 1) cnt++;
        if((v[i] + 1) & 1) cnt++;
        if(0 < cnt) sub *= cnt;
    }
    cout << sum - sub << endl;

    return 0;
}
