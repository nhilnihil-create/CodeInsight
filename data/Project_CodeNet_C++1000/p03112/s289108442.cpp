#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A,B,Q;
    cin >> A >> B >> Q;
    vl s, t;
    s.emplace_back(-LINF);
    rep(i,A){
        ll d;cin >> d;
        s.emplace_back(d);
    }
    s.emplace_back(LINF);
    t.emplace_back(-LINF);
    rep(i,B){
        ll d;cin >> d;
        t.emplace_back(d);
    }
    t.emplace_back(LINF);
    rep(i,Q){
        ll x;cin >> x;
        auto s2 = lower_bound(s.begin(),s.end(),x);
        auto s1 = s2;
        --s1;
        auto t2 = lower_bound(t.begin(),t.end(),x);
        auto t1 = t2;
        --t1;

        ll ans = LINF;
        chmin(ans, abs(x - *s1) + abs(*s1 - *t1));
        chmin(ans, abs(x - *t1) + abs(*t1 - *s1));
        chmin(ans, abs(x - *s1) + abs(*s1 - *t2));
        chmin(ans, abs(x - *t2) + abs(*t2 - *s1));
        chmin(ans, abs(x - *s2) + abs(*s2 - *t1));
        chmin(ans, abs(x - *t1) + abs(*t1 - *s2));
        chmin(ans, abs(x - *s2) + abs(*s2 - *t2));
        chmin(ans, abs(x - *t2) + abs(*t2 - *s2));
        printf("%lld\n", ans);
    }
}