#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int n;
    cin >> n;

    auto f = [&]{
        i64 a, b, c, d;
        cin >> a >> b >> c >> d;

        // 補充が間に合わない、最初に買えない
        if(b > d || a < b)
            return false;

        i64 gcd = __gcd(b, d);

        // 最初に落ちるまでシミュレーションした時の余り
        i64 mod = a % gcd;

        if(c < mod)
            return false;

        // c以下でmodが一定の中で最大になるような値
        i64 ma = ((c - mod) / gcd) * gcd + mod;

        i64 mi = ma - b + gcd;

        return mi >= 0;
    };

    for(int i = 0; i < n; ++i){
        cout << (f() ? "Yes" : "No") << endl;
    }
}
