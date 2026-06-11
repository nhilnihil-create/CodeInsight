#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+5;
char s[305][305],t[305][305];
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,ans=0;cin>>n;
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)cin>>s[i][j];
    for(ll b=0,a=0,f=1;b<n;b++,f=1){
        for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)t[i][j]=s[(i+a)%n][(j+b)%n];
        for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)f&=(t[i][j]==t[j][i]);
        ans+=(f*n);
    }
    cout<<ans;
}