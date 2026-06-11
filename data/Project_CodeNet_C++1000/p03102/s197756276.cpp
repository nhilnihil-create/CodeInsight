#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){ 
    int n, m, c; cin >> n >> m >> c;
    vector<int> B(m); rep(i, m)cin >> B[i];
    vector<vector<int>> A(n, vector<int>(m)); rep(i, n)rep(j, m)cin >> A[i][j];

    int res = 0;
    rep(i, n){
        int score = c;
        rep(j, m){
            score += A[i][j] * B[j];
        }
        if(score>0)res++;
    }
    cout << res << ln;
}

