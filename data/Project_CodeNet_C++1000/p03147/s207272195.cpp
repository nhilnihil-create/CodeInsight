/*
ID: hafiz.i1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define pi acos(-1.0)

using namespace std;



int main()
{
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,noz=0,d=0,s=0;
    cin>>n;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        if(l1[i]==0)noz++;
    }
    while(noz!=n){
        ll l=0,r=0,mv=1e18;
        for(int i=1;i<=n;i++){
            if(l1[i]!=0&&l==0)l=i;
            if(l1[i]!=0)r=i,mv=min(mv,l1[i]);
            else if(r>0)break;
        }
        s+=mv;
        for(int i=l;i<=r;i++)l1[i]-=mv;
        for(int i=1;i<=n;i++)if(l1[i]==0)d++;
        noz=d;d=0;
        //cout<<l<<" "<<r<<" "<<mv<<" "<<s<<" "<<noz<<endl;
    }
    cout<<s<<endl;
}
