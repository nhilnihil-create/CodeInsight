#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    ll d, g, ans = 10000, sum = 0, hoge = 0;
    vector<int> p(10), c(10);
    cin >> d >> g;
    rep(i, d) cin >> p[i] >> c[i];

    for (int bit = 0; bit < (1 << d);bit++){
        sum = 0;
        hoge = 0;
        for (int i = 0; i < d; i++) {
            if (bit & (1 << i)) {
            sum += c[i];
            sum += (i + 1) * 100 * p[i];
            hoge += p[i];
            }
        }
        if(sum >= g){
            ans = min(hoge, ans);
        }
        else{
            for (int i = d - 1; i >= 0;i--){
                if(bit & (1<<i))
                    continue;
                for (int j = 0; j < p[i]; j++)
                {
                    sum += (i+1) * 100;
                    hoge++;
                    if(sum >= g){
                        ans = min(hoge, ans);
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
