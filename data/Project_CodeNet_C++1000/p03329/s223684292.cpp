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

int main(){
    int N; cin >> N;
    vector<int> dp(N+1, 1000000);
    dp[0] = 0;

    vector<int> withdraw;
    for (int pow6 = 1; pow6 <= N; pow6 *= 6){
        withdraw.push_back(pow6);
    }
    for (int pow9 = 1; pow9 <= N; pow9 *= 9){
        withdraw.push_back(pow9);
    }

    rep(i, withdraw.size()){
        rep(j, N+1){
            if (j - withdraw[i] >= 0){
                dp[j] = min(dp[j], dp[j-withdraw[i]]+1);
            }
        }        
    }

    cout << dp[N] << endl;
}