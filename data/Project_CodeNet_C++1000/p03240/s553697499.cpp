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
    V<ll> x(n), y(n), h(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> h[i];

    int s;
    for(int i = 0; i < n; i++){
        if(h[i]){
            s = i;
            break;
        }
    }

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            bool flag = true;
            ll H = abs(x[s] - i) + abs(y[s] - j) + h[s];
            for(int k = 0; k < n; k++){
                ll tmp = max(H - abs(x[k] - i) - abs(y[k] - j), 0LL);
                if(tmp != h[k]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << i << " " << j << " " << H << endl;
                return 0;
            }
        }
    }
}
