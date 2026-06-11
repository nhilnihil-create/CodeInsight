#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(ll i=num, i##_len=(n); i<i##_len; ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const ll LLINF = 1LL<<60;
const int INTINF = 1<<30;
const int MOD = 1000000007;

void add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

ll dp[210000][4];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep(i,S.size()){
        rep(j,4){
            if (S[i] != '?') add(dp[i+1][j], dp[i][j]);
            else add(dp[i+1][j], dp[i][j] * 3 % MOD);
        }
        if (S[i] == 'A' || S[i] == '?') add(dp[i+1][1], dp[i][0]);
        if (S[i] == 'B' || S[i] == '?') add(dp[i+1][2], dp[i][1]);
        if (S[i] == 'C' || S[i] == '?') add(dp[i+1][3], dp[i][2]);
    }
    cout << dp[S.size()][3] << endl;
}