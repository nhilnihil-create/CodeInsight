#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define INF 1e9+7
#define LLINF 1e18
using namespace std;
const ll MOD = 1e9 +7;


int n,q;
string s;
char t[200010],d[200010];
int can(int x){
    int now=x;
    rep(i,q){
        if(s[now]==t[i]){
            if(d[i]=='L') now--;
            else now++;
        }
        if(now==-1) return 1;
        else if(now==n) return 2;
    }
    return 0;
}




int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>q>>s;
    rep(i,q) cin>>t[i]>>d[i];
    int l=0,r=n+1;
    while(r-1>l){
        int mid=(r+l)/2;
        if(can(mid)==1) l=mid;
        else r=mid;
    }
    int ans=l;
    l=0;r=n+1;
    while(r-1>l){
        int mid=(r+l)/2;
        if(can(mid)==2) r=mid;
        else l=mid;
    }
    ans +=n-r+1;
    if(ans>=n){
        cout<<0<<endl;
    }
    else cout<<n-ans<<endl;
    return 0;
}