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

int rec(int i){
    if(dp[i]<INF) return dp[i];
    if(i==0) return 0;
    
    int r=INF;
    chmin(r, rec(i-1)+1);
    for(int j=6; i-j>=0; j*=6) chmin(r, rec(i-j)+1);
    for(int j=9; i-j>=0; j*=9) chmin(r, rec(i-j)+1);
        
    return dp[i] = r;
}

int main(){
    int N;
    cin >> N;
    
    cout << rec(N) << endl;
    return 0;
}
