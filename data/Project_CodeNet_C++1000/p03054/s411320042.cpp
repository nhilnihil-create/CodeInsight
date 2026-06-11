#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll h,w,n;cin>>h>>w>>n;
    ll sr,sc;cin>>sr>>sc;
    string s,t;cin>>s>>t;
    ll lx=1,hx=h,ly=1,hy=w;
    for(ll i=n-1;i>=0;i--){
        if(t[i]=='R')ly = max(ly-1 , 1ll);
        if(t[i]=='D')lx = max(lx-1 , 1ll);
        if(t[i]=='L')hy = min(hy+1 , w);
        if(t[i]=='U')hx = min(hx+1 , h);

        if(s[i]=='R')hy--;
        if(s[i]=='D')hx--;
        if(s[i]=='L')ly++;
        if(s[i]=='U')lx++;

       if(hx<lx || hy<ly)return cout<<"NO" , 0;
    }
    if(hx<sr || sr<lx || hy<sc || sc<ly)return cout<<"NO" , 0;
    cout<<"YES";
}