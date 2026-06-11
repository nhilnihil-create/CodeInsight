#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n, k;
    cin >> n >> k;
    deque<ll> Que;
    rep(i, n){
        ll v; cin >> v;
        Que.push_back(v);
    }

    ll res = 0;
    rep(i, k+1){
        rep(j, k+1){
            if(i+j > n || i+j > k) continue;
            deque<ll> que = Que;
            vector<ll> jewel;
            ll val, sum = 0;
            rep(a, i){
                val = que.front(); que.pop_front();
                jewel.push_back(val); 
                sum += val;
            }
            rep(b, j){
                val = que.back(); que.pop_back();
                jewel.push_back(val);
                sum += val;
            }
            sort(all(jewel));
            rep(c, min((int)jewel.size(), k-(i+j))){
                ll num = jewel[c];
                if(num < 0)sum -= num;
            }
        chmax(res, sum);
        }
    }
    cout << res << ln;
}
