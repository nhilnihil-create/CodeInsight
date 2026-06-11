#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    int antena[5], k; rep(i, 5) cin >> antena[i]; cin >> k;
    bool fg = true;

    rep(i, 4){
        for(int j=i+1; j<5; j++){
            if(antena[j] - antena[i] > k) fg = false;
        }
    }
    if(fg) cout << "Yay!" << ln;
    else cout << ":(" << ln;
}