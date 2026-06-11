#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;





int main(){
    ll N; cin >> N;
    vector<ll> A;
    ll cache = -1;
    for(int i = 0; i < N; i++){
        ll x; cin >> x;
        if(x != cache) A.push_back(x);
        cache = x;
    }
    N = A.size();
    vector<ll> DP(N); DP[0] = 0;
    vector<ll> DP2(N+2);
    map<ll, pair<ll, ll>> M; // {num, {cnt, idx}}
    for(int i = 0; i < N; i++){
        ll x = A[i];
        auto p = M[x];
        ll c = p.first;
        ll idx = p.second;
        if(i != 0) DP[i] += DP[i-1]; 
        DP[i] %= MOD;
        DP[i] += c; 
        DP[i] %= MOD;
        if(c != 0 && idx-1 >= 0) {
            DP2[x] += DP[idx-1];
            DP[i] += DP2[x]; 
        }
        DP[i] %= MOD;

        M[x].first++;
        M[x].second = i;




    }
    cout << DP[N-1]+1 << endl;
     


}
