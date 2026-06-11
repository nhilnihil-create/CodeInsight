#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 1000000000000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    ll A,B,Q; cin>>A>>B>>Q;
    vector<ll> S(A+2);
    vector<ll> T(B+2);
    rep1(i,A)cin>>S.at(i);
    rep1(i,B)cin>>T.at(i);
    S.at(0) = T.at(0) = -INF;
    S.at(A+1) = T.at(B+1) = INF;
    rep(i,Q){
        ll x; cin>>x;
        auto iter1 = lower_bound(S.begin(),S.end(),x);
        auto iter2 = lower_bound(T.begin(),T.end(),x);
        auto ind1 = distance(S.begin(),iter1);
        auto ind2 = distance(T.begin(),iter2);
        ll s_b,s_f,t_b,t_f;
        s_f=(S.at(ind1)-x);
        s_b=x-S.at(ind1-1);
        t_f=(T.at(ind2)-x);
        t_b=x-T.at(ind2-1);
        ll r1 = max(s_f,t_f);
        ll r2 = max(s_b,t_b);
        ll r3 = min(2*s_b+t_f,2*t_b+s_f);
        ll r4 = min(2*s_f+t_b,2*t_f+s_b);
        cout<<min({r1,r2,r3,r4})<<endl;
    }
}
