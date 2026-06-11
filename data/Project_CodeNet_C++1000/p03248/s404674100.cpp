#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+5;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;cin>>s;
    ll n = s.size();
    s="0" + s;
    if(s[n]=='1' || s[1]=='0')return cout<<"-1" , 0;
    for(ll i=1;i<=n-1;i++)if(s[i]!=s[n-i])return cout<<"-1" , 0;
    for(ll i=1,u=1,prv=0;i<=n-1;i++){
        if(s[i]=='0')continue;
        ll v=u+i-prv;
        for(ll j=u+1;j<=v;j++)cout<<u<<" "<<j<<"\n";
        u=v,prv=i;
    }
}