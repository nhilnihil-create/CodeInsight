#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int main() {

    ll N,M;
    cin >> N >> M;

    ll L[M],R[M];
    rep(i,M){
        cin >> L[i] >> R[i];
    }

    ll maxL = 0;
    ll minR = N;

    rep(i,M){
        if(maxL < L[i]){
            maxL = L[i];
        }
        if(minR > R[i]){
            minR = R[i];
        }
    }

    ll ans = minR - maxL + 1;
    if(ans >= 0){
        cout << ans << endl;
        return 0;
    }

    cout << 0 << endl;


}