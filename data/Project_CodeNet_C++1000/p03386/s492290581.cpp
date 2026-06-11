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
    ll a,b,k;map<ll,ll>m;
    cin>>a>>b>>k;
    for(int i=a;i<=min(a+k-1,b);i++){m[i]=1;cout<<i<<endl;}
    for(int i=max(b-k+1,a);i<=b;i++){if(m[i]!=1)cout<<i<<endl;}
}
