#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int n, h, w;
    cin >> n >> h >> w;
    int c = 0;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a >= h && b >= w)
            ++c;
    }
    cout << c << endl;
}
