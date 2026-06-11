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
    ll a[4],b,c,x,y=1,s=0;
    cin>>a[1]>>a[2]>>a[3]>>x;
    //s=max({a,b,c});
    for(int i=1;i<=x;i++)y*=2;
    sort(a+1,a+3+1);
    for(int i=1;i<=2;i++){
        s+=a[i];
    }
    s+=(ll)(a[3]*y);
    cout<<s;
}
