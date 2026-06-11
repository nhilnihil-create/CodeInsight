#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    int n; cin >> n;
    V<V<int> > f(n, V<int>(10));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cin >> f[i][j];
        }
    }
    V<V<int> > c(n, V<int>(11));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 11; j++){
            cin >> c[i][j];
        }
    }

    ll ans = -INF;
    for(int bit = 1; bit < (1 << 10); bit++){
        ll sum = 0;
        for(int i = 0; i < n; i++){
            ll cnt = 0;
            for(int j = 0; j < 10; j++){
                if(bit & (f[i][j] << j)){
                    cnt++;
                }
            }
            sum += c[i][cnt];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;

}
