#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll h,w; cin>>h>>w;
    char s[h][w];
    rep(i,h)rep(j,w) cin>>s[i][j];

    ll di[]={1,1,1,0,0,-1,-1,-1},dj[]={1,0,-1,1,-1,1,0,-1};
    rep(i,h){
        rep(j,w){
            ll num=0;
            if(s[i][j]=='#') continue;
            rep(k,8){
                ll ni=i+di[k],nj=j+dj[k];
                if(ni<0||h<=ni||nj<0||w<=nj) continue;
                if(s[ni][nj]=='#') num++;
            }
            s[i][j]=num+'0';
        }
    }
    rep(i,h)rep(j,w){
        cout<<s[i][j];
        if(j==w-1) cout<<endl;
    }
    return 0;
}