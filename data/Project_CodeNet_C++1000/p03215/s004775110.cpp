#include <bits/stdc++.h>

#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"

using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;

template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N, K;
ll a[1010];
vector<ll> A;

signed main(){
    cin >> N >> K;
    REP(i, N) cin >> a[i];
    REP(i, N){
        ll sum = 0;
        FOR(j, i, N){
            sum += a[j];
            A.push_back(sum);
        }
    } 
    ll ans = 0;
    for(ll i = 40; i >= 0; i--){
        int cnt = 0;
        for(auto a : A){
            if(((ans + (1LL << i)) & a) == ans + (1LL << i)) cnt++;
        }
        if(cnt >= K) ans += (1LL << i);
    }
    PRINT(ans);
    return 0;
}