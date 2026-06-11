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


int main() {    
    int n, m; cin >> n >> m;
    vector<pll> drinks(n);
    rep(i, n){
        ll a, b; cin >> a >> b;
        drinks[i] = pll(a, b);
    }
    sort(all(drinks));

    ll res = 0, cnt = 0;
    rep(i, n){
        if(m - cnt > drinks[i].second){ //必要本数 > 購入可能本数
            res += drinks[i].first * drinks[i].second;
            cnt += drinks[i].second;
        }else{
            res += (m - cnt) * drinks[i].first;
            break;
        }
    }
    cout << res << ln;
} 
