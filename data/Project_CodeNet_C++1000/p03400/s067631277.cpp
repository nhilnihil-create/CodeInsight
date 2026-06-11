#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool revp2(const pair<ll,ll>&a,const pair<ll,ll>&b){return a.first>b.first;}
bool revp3(const pair<ll,ll>&a,const pair<ll,ll>&b){if(a.first==b.first)return a.second<b.second;
return a.first>b.first;}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    ll n,s=0;
    cin>>n;
    ll d,x;
    cin>>d>>x;
    ll a;
    for(int i=1;i<=n;i++){
        cin>>a;ll j=1;
        while(a*j+1<=d)s++,j++;
    }
    cout<<x+n+s;
}
