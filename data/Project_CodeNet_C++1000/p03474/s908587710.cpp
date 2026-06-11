#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,ll>f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b,x=0,y=0;
    cin>>a>>b;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(i==a && s[i]=='-')x++;
        if(s[i]>='0' && s[i]<='9')y++;
    }
    if(x==1&&y==a+b)cout<<"Yes\n";
    else cout<<"No\n";
}
