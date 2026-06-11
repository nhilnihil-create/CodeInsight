#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll H, W, D, Q, ans=0, tmp=0;
vector<vector<ll>> A,S;
vector<pair<ll,ll>> P;

signed main(){
    cin >> H >> W >> D;
    P.resize(H*W);
    S.resize(D);
    for(int i=0;i<D;i++) {
        S[i].resize(H*W/D+1,0);
    }
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            ll a;
            cin >> a;
            a--;
            P[a] = make_pair(i,j);
        }
    }
    for(int i=0;i<D;i++) {
        for(int j=i+D;j<H*W;j+=D) {
            S[i][(j-i)/D] += S[i][(j-i-D)/D] + abs(P[j].first-P[j-D].first) + abs(P[j].second-P[j-D].second);
        }
    }
    cin >> Q;
    for(int i=0;i<Q;i++) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << S[l%D][(r-r%D)/D]-S[l%D][(l-l%D)/D] << endl;
    }
    return 0;
}