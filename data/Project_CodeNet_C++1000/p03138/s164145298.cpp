#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 998244353;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {   
    ll n, k; cin >> n >> k;
    vector<ll>A(n); rep(i, n) cin >> A[i];

    ll dp[60][2];
    rep(i, 60)rep(j, 2) dp[i][j] = -1;
    dp[0][0] = 0; //i桁目まで見たときのXORの合計の最大値, smaller

    int num =50;
    rep(i, num){
        ll mask = 1LL << (num - i - 1);
        ll cnt0 = 0, cnt1 = 0;
        int c = 0;
        rep(j, n) if(A[j] & mask)c++;
        cnt0 = mask * c;
        cnt1 = mask * (n - c);

        //smaller -> smaller
        if(dp[i][1] != -1){
            chmax(dp[i+1][1], dp[i][1] + max(cnt1, cnt0));
        }
        //exact -> smaller
        if(dp[i][0] != -1){
            if(k & mask){
                chmax(dp[i+1][1], dp[i][0] + cnt0);
            }
        }
        //exact -> exact
        if(dp[i][0] != -1){
            if(k & mask)chmax(dp[i+1][0], dp[i][0] + cnt1);
            else chmax(dp[i+1][0], dp[i][0] + cnt0);
        }
    }

    cout << max(dp[num][0], dp[num][1]) << ln;
}
