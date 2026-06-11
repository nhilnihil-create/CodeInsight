#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int A,B,Q;
    cin >> A >> B >> Q;
    vector<ll> S;
    vector<ll> T;
    rep(i,A) {
        ll s;
        cin >> s;
        S.push_back(s);
    }
    rep(i,B) {
        ll t;
        cin >> t;
        T.push_back(t);
    }
    sort(S.begin(),S.end());
    sort(T.begin(),T.end());
    
    rep(i,Q) {
        ll ans = 1e18;
        ll x;
        cin >> x;
        auto idx_s = lower_bound(S.begin(),S.end(), x) - S.begin();
        auto idx_t = lower_bound(T.begin(),T.end(), x) - T.begin();

        int idx_sm = idx_s-1;
        int idx_tm = idx_t-1;
        if (idx_s==S.size()) idx_s = -1;
        if (idx_t==T.size()) idx_t = -1;

        if (idx_s!=-1 && idx_t!=-1) {
            ll tmp = max(S[idx_s]-x, T[idx_t]-x);
            ans = min(ans,tmp);
        }
        if (idx_sm!=-1 && idx_tm!=-1) {
            ll tmp = max(x-S[idx_sm], x-T[idx_tm]);
            ans = min(ans,tmp);
        }
        if (idx_s!=-1 && idx_tm!=-1) {
            ll tmp = S[idx_s]-x + 2*(x-T[idx_tm]);
            ans = min(ans,tmp);
            tmp = x-T[idx_tm] + 2*(S[idx_s]-x);
            ans = min(ans,tmp);
        }
        if (idx_t!=-1 && idx_sm!=-1) {
            ll tmp = T[idx_t]-x + 2*(x-S[idx_sm]);
            ans = min(ans,tmp);
            tmp = x-S[idx_sm] + 2*(T[idx_t]-x);
            ans = min(ans,tmp);
        }
        cout << ans << endl;

    }
}
