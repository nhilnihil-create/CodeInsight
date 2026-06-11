#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll N; cin >> N;
    vector<pair<ll, ll>> P(N);
    for(int i = 0; i < N; i++){
        ll x; cin >> x;
        P[i] = {x, i};
    }
    sort(P.begin(), P.end());
    ll l = N/2-1, r = N/2;
    unordered_map<ll, ll> M;
    for(int i = 0; i < N/2; i++) M[P[i].second] = P[r].first;
    for(int i = N/2; i < N; i++) M[P[i].second] = P[l].first;

    for(int i = 0; i < N; i++) cout << M[i] << endl;


} 
