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
    ll l1[n+2],l2[n+2];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
    }l1[0]=0,l1[n+1]=0;
    for(int i=1;i<=n;i++){
        if(i<n)l2[i]=abs(l1[i]-l1[i+2]);
        else l2[i]=abs(l1[n]);
        if(i==1||i==n)s+=abs(l1[i]);
        else s+=abs(l1[i]-l1[i-1]);
    }
    s+=abs(l1[n]-l1[n-1]);
    l2[0]=abs(l1[2]);
    //cout<<s<<endl;
    for(int i=1;i<=n;i++){
        cout<<s-abs(l1[i-1]-l1[i])-abs(l1[i]-l1[i+1])+l2[i-1]<<endl;
    }
}
