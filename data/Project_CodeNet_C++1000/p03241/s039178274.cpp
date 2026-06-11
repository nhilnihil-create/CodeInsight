#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

vector<ll> enum_divisors(ll N){
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i){
        if (N % i == 0){
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main(){
    ll N, M; cin >> N >> M;

    ll ans = 0;
    vector<ll> divisors = enum_divisors(M);
    for (ll divisor : divisors){
        if (divisor * N <= M){
            ans = divisor;
        }
    }

    cout << ans << endl;
}