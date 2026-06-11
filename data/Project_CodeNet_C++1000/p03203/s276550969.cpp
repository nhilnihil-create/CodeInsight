#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll cur=0,h,w,n;cin>>h>>w>>n;
    vector<ll> pos(h+1,w);
    pos[h]=0;
    for(ll i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        x--;y--;
        pos[x]=min(pos[x],y);
    }
    for(ll i=1;i<=h;i++){
        if(pos[i]<=cur)return cout<<i , 0;
        if(pos[i]==cur+1)continue;
        cur++;
    }
}