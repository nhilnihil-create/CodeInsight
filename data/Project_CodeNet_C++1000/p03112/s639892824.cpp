#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

int main(){
    ll A,B,Q; cin>>A>>B>>Q;
    vec s(A+2,-INF),t(B+2,-INF);
    rep(i,A) cin>>s[1+i];
    rep(i,B) cin>>t[1+i];
    s[A+1]=INF, t[B+1]=INF;
    vec ans;
    vec Que(Q);
    rep(i,Q) cin>>Que[i];
    rep(i,Q){
        ll x=Que[i];
        ll k1=lower_bound(ALL(s),x)-s.begin();
        ll A1=s[k1]-x, A2=x-s[k1-1];
        ll k2=lower_bound(ALL(t),x)-t.begin();
        ll B1=t[k2]-x, B2=x-t[k2-1];
        vec p(6);
        //cout<<i<<':'<<A1<<' '<<A2<<' '<<B1<<' '<<B2<<endl;
        p[0]=max(A2,B2);
        p[1]=max(A1,B1);
        p[2]=2*A1+B2;
        p[3]=2*A2+B1;
        p[4]=2*B1+A2;
        p[5]=2*B2+A1;
        sort(ALL(p));
        ans.pb(p[0]);   
    }
    rep(i,ans.size()) cout<<ans[i]<<endl;
}