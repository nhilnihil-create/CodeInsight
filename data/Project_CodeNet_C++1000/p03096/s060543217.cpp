#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vector<int> places[210000];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> c(N);
    for(int i = 0; i < N; i++){
        cin >> c[i];
    }

    ll MOD = 1e9+7;

    ll dp[210000];
    dp[0] = 1;

    for(int i = 0; i < 210000; i++) places[i].clear();
    for(int i = 0; i < N; i++) places[c[i]].push_back(i);

    for(int i = 1; i <= N; i++){

        dp[i] = (dp[i] + dp[i-1]) % MOD;

        int color = c[i-1];
        int it = lower_bound(places[color].begin(), places[color].end(), i-1)
            - places[color].begin();
        if(it > 0){
            int j = places[color][it-1];
            if((i-1) - j > 1) dp[i] = (dp[i] + dp[j+1]) % MOD;
        }
    }
    cout << dp[N] << endl;


    return 0;
}

