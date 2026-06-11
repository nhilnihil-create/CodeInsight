#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n; cin >> n;

    int ans = 1;
    for(int i = 2; i <= 1000; i++){
        for(int j = 2; j <= 1000; j++){
            if(pow(i, j) > ans && pow(i, j) <= n) ans = pow(i, j);
        }
    }
    cout << ans << endl;
}
