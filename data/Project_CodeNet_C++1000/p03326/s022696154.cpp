#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,M;
    cin >> N >> M;
    ll X[N],Y[N],Z[N];

    rep(i,N) {
        ll x,y,z;
        cin >> x >> y >> z;
        X[i] = x;
        Y[i] = y;
        Z[i] = z;
    }
    ll ans = 0;
    for (int bit=0; bit<(1<<3); bit++) {
        vector<ll> tmp(0);
        rep(i,N) {
            ll x, y, z;
            if (bit & (1<<2)) x = X[i];
            else x = -X[i];
            if (bit & (1<<1)) y = Y[i];
            else y = -Y[i];
            if (bit & (1<<0)) z = Z[i];
            else z = -Z[i];

            ll t = x + y + z;
            tmp.push_back(t);
        }
        sort(tmp.begin(),tmp.end());
        reverse(tmp.begin(),tmp.end());
        ll ans_tmp = 0;
        rep(i,M) {
            ans_tmp += tmp[i];
        }
        ans = max(ans, ans_tmp);
    }
    cout << ans << endl;
}
