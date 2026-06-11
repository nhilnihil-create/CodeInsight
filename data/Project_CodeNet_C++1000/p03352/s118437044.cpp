#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int x; cin >> x;

    // i=1~1000のべき乗数の元
    // j=べき乗の指数
    // 1~1000についてすべてのべき乗数を試す
    int ans = 1;
    for(int i = 2; i <= 1000; i++){
        for(int j = 2; j <= 1000; j++){
            int p = pow(i, j);
            if(ans < p && p <= x) ans = p;
        }
    }
    cout << ans << endl;

    // 冗長な解答
    // // xをデクリメントして検証する
    // for(int i = x; i > 0; i--){
    //     // iがべき乗数かを2から判定する
    //     for(int j = 2; j * j <= i; j++){
    //         int n = j;
    //         while(n < i) n *= j;
    //         // nがiと同じであればべき乗数
    //         if(n == i){
    //             cout << i << endl;
    //             return 0;
    //         }
    //     }
    // }
    // cout << 1 << endl;
    return 0;
}
