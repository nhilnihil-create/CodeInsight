#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll h,w; cin>>h>>w;
    string s[h];
    rep(i,h) cin>>s[i];
    ll dy[8]={1,1,1,0,0,-1,-1,-1};
    ll dx[8]={1,0,-1,1,-1,1,0,-1};
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#') continue;

            ll num=0;
            rep(k,8){
                ll ni=i+dy[k];
                ll nj=j+dx[k];
                if(ni<0||h<=ni) continue;
                if(nj<0||w<=nj) continue;

                if(s[ni][nj]=='#') num++;
            }
            s[i][j]=num+'0';
        }
    }
    rep(i,h) cout<<s[i]<<endl;
    return 0;
}

