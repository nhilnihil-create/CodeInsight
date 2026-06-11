#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
    ll n, k; cin >> n >> k;
    ll zero[61]={0}, one[61]={0};
    ll kkk[61] = {0};
    rep(j,60){
        if((k>>j)&1) kkk[j]++;
    }
    rep(i, n){
        ll A;
        cin >> A;
        rep(j,60){
            if((A>>j)&1) one[j]++;
            else zero[j]++;
        }
    }
    bool miman = false;
    ll ans = 0;
    for(int j=60;j>=0;j--) {
        if(!miman && one[j] == 0 && kkk[j] == 0) continue;
        if(miman) {
            ans += (1ll<<j)*max(zero[j],one[j]);
        } else {
            if(kkk[j] && one[j] > zero[j]) {
                miman = true;
                ans += (1ll<<j)*max(zero[j],one[j]);
            } else {
                if(kkk[j] == 0) {
                    ans += (1ll<<j)*one[j];
                } else {
                    ans += (1ll<<j)*zero[j];
                }
            }
        }
        //cout << ans << endl;
    }
    cout << ans;
}
