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
    int h, w; cin >> h >> w;

    V<V<int> > c(10, V<int>(10, INT_INF));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> c[i][j];
        }
    }

    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(c[i][j] > c[i][k] + c[k][j]) c[i][j] = c[i][k] + c[k][j];
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int a; cin >> a;
            if(a != -1) ans += c[a][1];
        }
    }
    cout << ans << endl;
}
