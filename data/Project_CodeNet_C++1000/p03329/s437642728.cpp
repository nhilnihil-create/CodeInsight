#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i <(n); i++)
#define rep2(i,l,r) for (int i=(l); i<(r); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll INF = 1e10;
vector<int> v(100110);
vector<ll> dp(100110, INF);

int main(){
    int N;
    cin >> N;
    
    dp[0] = 0;
    rep(i, N) {
        chmin(dp[i+1], dp[i]+1);
        
        for(int j=6; i+j <= N+1; j*=6)
            chmin(dp[i+j], dp[i]+1);
            
        for(int j=9; i+j <= N+1; j*=9)
            chmin(dp[i+j], dp[i]+1);
    }
    
    cout << dp[N] << endl;
    return 0;
}
