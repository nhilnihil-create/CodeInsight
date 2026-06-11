#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool dp[8005][32005];
bool func(vector<ll> &v,ll p){
    memset(dp,0,sizeof(dp));
    dp[0][16000]=1;
    for(ll i=0,n=v.size();i<n;i++){
        for(ll j=0;j<=32000;j++){
            if(dp[i][j]==false)continue;
            dp[i+1][j+v[i]]=dp[i+1][j-v[i]]=1;
        }
    }
    return dp[v.size()][16000+p];
}
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    string s;cin>>s;
    ll x,y;cin>>x>>y;
    vector<ll> vx,vy;
    for(ll i=0,n=s.size(),cnt=0,flg=0;i<=n;i++){
        if(i!=n && s[i]=='F')cnt++;
        else{
            if(flg==0)vx.push_back(cnt);
            else vy.push_back(cnt);
            cnt=0,flg^=1;
        }
    }
    x-=vx[0];
    vx.erase(vx.begin());
    if(func(vx,x) && func(vy,y))cout<<"Yes";
    else cout<<"No";
}