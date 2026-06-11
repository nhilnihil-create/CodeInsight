#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n;
    cin >> n;

    double mi = 999999999999999.0 / 135;
    ll ten = 1e10;
    vector<ll> ans;
    rep(loop, 8){
        ll tmp = 100000;
        while(tmp > 10000){
            ll x = tmp * ten - 1;
            ll cnt = 0;
            ll xx = x;
            rep(j,20){
                cnt += xx % 10;
                xx /= 10;
            }
            if((double)x / cnt <= mi){
                ans.push_back(x);
                mi = (double)x / cnt;
            }
            tmp--;
        }
        ten /= 10;
    }

    drep(i,10000000){
        if(i == 0)break;
        ll x = i;
        ll cnt = 0;
        ll xx = x;
        rep(j,20){
            cnt += xx % 10;
            xx /= 10;
        }
        if((double)x / cnt <= mi){
            ans.push_back(x);
            mi = (double)x / cnt;
        }
    }
    reverse(ans.begin(), ans.end());
    rep(i,n)cout << ans[i] << endl;
    return 0;
}
 
 
