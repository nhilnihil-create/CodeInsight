#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int A, B, Q; cin >> A >> B >> Q;
    vector<ll> S(A+2);
    vector<ll> T(B+2);
    S[0] = T[0] = -110000000000000;
    S[A+1] = T[B+1] = 110000000000000;
    rep(i, A) cin >> S[i+1];
    rep(i, B) cin >> T[i+1];
    int direction[2] = {0, -1};
    rep(i, Q){
        ll x; cin >> x;
        auto sx = lower_bound(S.begin(), S.end(), x);
        auto tx = lower_bound(T.begin(), T.end(), x);
        ll ans = 20000000000000000;
        for(int i : direction){
            // cout << *(sx-1) << endl;
            for(int j : direction){
                ans = min(ans, min(abs(*(sx+i)-x) + abs(*(sx+i)-*(tx+j)), abs(*(tx+j)-x) + abs(*(sx+i)-*(tx+j))));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
