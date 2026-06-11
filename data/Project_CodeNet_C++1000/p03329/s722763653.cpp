#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long,long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

const int INF = 1e9;

int pow(int a, int n) {
    int ans = 1;
    REP(i,n) ans *= a;
    return ans;
}

vecveci dp(20,veci(100010));

int main() {
    int N; cin >> N;
    veci A;
    A.push_back(1);
    int cnt = 1;
    while(1) {
        if(pow(6,cnt) > 100000) break;
        else A.push_back(pow(6,cnt));
        cnt++;
    }
    cnt = 1;
    while(1) {
        if(pow(9,cnt) > 100000) break;
        else A.push_back(pow(9,cnt));
        cnt++;
    }
    int X = A.size();
    REP(j,100010) dp[0][j] = INF;
    REP(i,X) REP(j,100010) {
        if(j < A[i] && i > 0) dp[i+1][j] = dp[i][j];
        else dp[i+1][j] = min(dp[i][j],dp[i+1][j-A[i]]+1);
    }
    cout << dp[X][N]-1 << endl;
}