#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    rep(i,n) cin >> x[i] >> y[i] >> h[i];
    for(int cy = 0; cy <= 100; ++cy){
        for(int cx = 0; cx <= 100; ++cx){
            int H;
            rep(i,n){
                if(h[i] > 0){
                    H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                    break;
                }
            }
            bool ok = true;
            rep(i,n){
                int high = H - abs(x[i] - cx) - abs(y[i] - cy);
                chmax(high, 0);
                if(h[i] != high){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
    return 0;
}
