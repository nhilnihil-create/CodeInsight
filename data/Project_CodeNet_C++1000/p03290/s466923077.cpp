#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main(){
    ll D, G;
    cin >> D >> G;
    vector<ll> p(D), c(D);
    for (int i = 0; i < D; i++)cin >> p[i] >> c[i];
    ll cnt = INF;

    for (int bit = 0; bit < (1 << D); bit++) {
        ll sum = 0;
        ll tmp_cnt = 0;

        for (int i = 0; i < D; i++) {
          if (bit & (1 << i)) {
            sum += c[i];
            sum += 100 * (i + 1) * p[i];
            tmp_cnt += p[i];
          }
        }

        if(sum<G){
          for (int j = D - 1; j >= 0; j--){
              if(!(bit & (1<<j))){
                for (int k = 1; k <= p[j]; k++){
                  if (sum >= G) break;
                  sum += 100 * (j + 1);
                  tmp_cnt++;
                }
              }
          }
        }
        cnt = min(cnt, tmp_cnt);
    }
    cout << cnt << endl;
    return 0;
}