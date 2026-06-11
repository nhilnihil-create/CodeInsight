#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll N, M; cin >> N >> M;
    vector<vector<ll>> V(M);
    vector<ll> P(M);
    for(int i = 0; i < M; i++){
        ll k; cin >> k;
        for(int j = 0; j < k; j++){
            ll s; cin >> s; s--;
            V[i].push_back(s);
        }
    } 
    for(int i = 0; i < M; i++) cin >> P[i];

    ll ans = 0;
    for(int i = 0; i < (1<<N); i++){
        bitset<10> B = i;
        ll SUM = 0;
        for(int j = 0; j < M; j++){
            ll cnt = 0;
            for(auto x : V[j]){
                if(B[x]) cnt++;
            }
            if(cnt%2==P[j]) SUM++;
        }
        if(SUM == M) ans++;
    }
    cout << ans << endl;
} 
