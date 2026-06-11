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
    string s[50];
    rep(i,h) cin>>s[i];

    ll di[8]={1,1,1,0,0,-1,-1,-1};
    ll dj[8]={1,0,-1,1,-1,1,0,-1};
    
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#') continue;
            ll cnt=0;
            rep(k,8){
                ll ni=i+di[k];
                ll nj=j+dj[k];
                if(ni<0||nj<0||h<=ni||w<=nj) continue;
                else if(s[ni][nj]=='#') cnt++;
            }
            s[i][j]=cnt+'0';
        }
    }
    rep(i,h) cout<<s[i]<<endl;
    return 0;
}
