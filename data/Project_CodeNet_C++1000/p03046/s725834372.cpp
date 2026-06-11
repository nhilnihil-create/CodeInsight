#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll vis[1000005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m,k;
    cin>>m>>k;
    ll n=pow(2,m);
    if(k>=n||(k==1&&m==1)){
        cout<<"-1";
        exit(0);
    }
    else if(k==0){
        for(ll i=0;i<n;i++)
        cout<<i<<" "<<i<<" ";
        exit(0);
    }
    for(ll i=0;i<n;i++)
    if(!vis[i]){
        cout<<i<<" "<<(k^i)<<" ";
        vis[k^i]=1;
    }
    for(ll i=0;i<1000005;i++)
    vis[i]=0;
    for(ll i=0;i<n;i++)
    if(!vis[i]){
        cout<<(k^i)<<" "<<i<<" ";
        vis[k^i]=1;
    }
}