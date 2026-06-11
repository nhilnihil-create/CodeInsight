#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N+1);
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
    }
    vector<ll> S(N+1);
    S[0] = 0;
    for (ll i = 1; i <= N; i++) {
        S[i] = S[i-1] + A[i];
    }

    ll ans = INF;
    ll b1,b2,c1,c2,d1,d2,e1,e2;
    ll tmp, ind;
    for (ll k = 2; k < N-1; k++) {
        tmp = S[k] / 2 + 1;
        ind = lower_bound(S.begin() + 1, S.begin() + k, tmp) - S.begin();
        b1 = S[ind]; c1 = S[k] - S[ind];
        b2 = S[ind - 1]; c2 = S[k] - S[ind - 1];

        tmp = (S[N] - S[k]) / 2 + S[k] + 1;
        ind = lower_bound(S.begin() + k, S.end(), tmp) - S.begin();
        d1 = S[ind] - S[k]; e1 = S[N] - S[ind];
        d2 = S[ind - 1] - S[k]; e2 = S[N] - S[ind - 1];        

        tmp = max({b1,c1,d1,e1}) - min({b1,c1,d1,e1});
        ans = min(ans, tmp);
        tmp = max({b1,c1,d2,e2}) - min({b1,c1,d2,e2});
        ans = min(ans, tmp);
        tmp = max({b2,c2,d1,e1}) - min({b2,c2,d1,e1});
        ans = min(ans, tmp);
        tmp = max({b2,c2,d2,e2}) - min({b2,c2,d2,e2});
        ans = min(ans, tmp);    
    }
    printf("%lld\n", ans);


}
