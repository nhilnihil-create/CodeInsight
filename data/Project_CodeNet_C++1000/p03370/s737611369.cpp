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
    ll n,x,a=10000,s=0;
    cin>>n>>x;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        a=min(a,l1[i]);
        s+=l1[i];
    }
    cout<<n+(x-s)/a;

}
