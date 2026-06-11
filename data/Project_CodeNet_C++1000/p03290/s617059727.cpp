#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;
int divup(int x,int y){
    if(x%y==0)return x/y;
    else return x/y+1;
}

signed main(){
    int d,g;cin>>d>>g;
    int p[d],c[d];
    REP(i,d)cin>>p[i]>>c[i];
    int ans=INF;
    for(int tmp=0;tmp<(1<<d);tmp++){
        int sp=0;
        int sum=0;
        int MA=-1;
        REP(i,d){
            if(tmp>>i & 1){
                sp+=100*(i+1)*p[i]+c[i];
                sum+=p[i];
            }
          	else chmax(MA,i);
        }
        if(sp>=g)chmin(ans,sum);
        else{
            if(MA==-1)continue;
            int d=divup(g-sp,(MA+1)*100);
            if(d<=p[MA]){
                sum+=d;
                sp+=d*100*(MA+1);
            }
            if(sp>=g)chmin(ans,sum);
        }
    }
    cout<<ans<<endl;
}