#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

#ifdef DEBUG
#define DBG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#else
#define DBG(fmt, ...)
#endif

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N, M;
    cin >> N >> M;

    vector<ll> con(M);
    REP(i, M){
        ll K;
        cin >> K;
        ll c = 0;
        REP(j, K){
            ll s;
            cin >> s;
            s--;
            c |= (1<<s);
        }
        con[i]=c;
    }

    vector<ll> P(M);
    REP(i, M){
        cin >> P[i];
    }

    ll ans = 0;
    for(int s =0; s < (1<<N); s++){
        ll count = 0;
        for(int i = 0; i < M; i++ ){
            ll on = s & con[i];
            if( __builtin_popcount(on) % 2 == P[i] ){
                count++;
            }else{
                break;
            }
        }

        if( count == M ){
          ans++;
        }

    }
    cout << ans << endl;
    return 0;
}
