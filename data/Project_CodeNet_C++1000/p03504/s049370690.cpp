#include <bits/stdc++.h>
using namespace std;typedef long long ll;typedef vector<ll> vl;typedef vector<vl> vvl;typedef pair<ll,ll> pl;typedef vector<pl> vp;const ll INF=1001001001;const ll LINF=1001001001001001001;const ll D4[]={0,1,0,-1,0};const ll D8[]={0,1,1,0,-1,-1,1,-1,0};template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define rep(i,n) fore(i,0,(n)-1)
#define all(x) (x).begin(),(x).end()

void solve(long long N, long long C, std::vector<long long> s, std::vector<long long> t, std::vector<long long> c){
    vvl a(C,vl(100005));
    rep(i,N){
        a[c[i]-1][s[i]]++;
        a[c[i]-1][t[i]]--;
    }
    vl al(100005);
    rep(i,C)rep(j,100003){
        if(a[i][j]>0)al[j-1]+=a[i][j];
        else al[j]+=a[i][j];
    }
    ll ans=0;
    rep(i,100003){
        chmax(ans,al[i]);
        al[i+1]+=al[i];
    }
    cout<<ans<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long C;
    scanf("%lld",&C);
    std::vector<long long> s(N);
    std::vector<long long> t(N);
    std::vector<long long> c(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&s[i]);
        scanf("%lld",&t[i]);
        scanf("%lld",&c[i]);
    }
    solve(N, C, std::move(s), std::move(t), std::move(c));
}
