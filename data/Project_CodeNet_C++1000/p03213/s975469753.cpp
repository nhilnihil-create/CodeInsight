#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;


vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(){
    int N; cin >> N;

    map<ll, int> prime_counter;
    for (int i = 2; i <=N; i++){
        vector<pair<ll,ll>> pfs = prime_factorize(i);
        for (auto pf : pfs) prime_counter[pf.first] += pf.second;
    }

    int prime_count = prime_counter.size();
    vector<vector<int>> dp(prime_count+1, vector<int>(76, 0));
    dp[0][1] = 1;

    int i = 0;
    for (auto pc : prime_counter){
        for (int j = 0; j <= 75; j++){
            for (int k = 1; k <= pc.second+1; k++){
                if (k*j <= 75) dp[i+1][k*j] += dp[i][j];
            }
        }
        i++;
    }

    cout << dp[prime_count][75] << endl;

}