#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

bool check[11];

int main() {
    int D, G; cin >> D >> G;
    vector<int> p(D), c(D);
    rep(i, D){
        cin >> p[i] >> c[i];
    }

    int ans = 1001001001;
    for (int i = 0; i < 1<<D; i++){
        int restMin = -1;
        int cnt = 0;
        int now = 0;
        for (int j = 0; j < D; j++){
            if(i>>j&1){
                cnt += p[j];
                now += (j+1)*100 * p[j] + c[j];
            } else {
                restMin = j;
            }
        }

        if(now < G){
            int x = G - now - 1;
            x /= (restMin+1) * 100;
            x++;
            if(x > p[restMin]-1){
                continue;
            }
            cnt += x;
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}