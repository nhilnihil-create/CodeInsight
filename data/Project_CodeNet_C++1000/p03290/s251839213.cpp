#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

int D;
ll G;
vector<ll> p, c;
signed main() {
    int D;
    ll G;
    cin >> D >> G;
    p.resize(D); c.resize(D);
    rep(i, D) cin >> p[i] >> c[i];

    ll res = 1<<29;
    for(int bit = 0; bit < (1<<D); bit++){
        ll sum = 0;
        ll num = 0;
        for(int i = 0; i < D; i++){
            if(bit & (1<<i)) sum += c[i] + p[i] * 100 * (i+1), num +=p[i];
        }

        if(sum >= G) res = min(res, num);
        else{
            for(int i = D -1; i >= 0; i--){
                if(bit & (1<<i)) continue;
                for(int j = 0; j < p[i]; j++){
                    if(sum >= G) break;
                    sum += 100 * (i+1);
                    ++num;
                }
            }
            res = min(res, num);
        }
    }
    cout << res << endl;

    return 0;
}