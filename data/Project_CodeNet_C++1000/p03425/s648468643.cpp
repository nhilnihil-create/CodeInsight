#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    ll x;
//    x=1ll << 59;
//    ll y=(1ll << 59) - 1ll;
//    cout<<((double)(x)==(double)(x-1))<<endl;
    ll n,X=0,X2=0,X3=0,X4=0,X5=0;
    cin>>n;
    string l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        if(l1[i][0]=='M')X++;
        else if(l1[i][0]=='R')X2++;
        else if(l1[i][0]=='A')X3++;
        else if(l1[i][0]=='C')X4++;
        else if(l1[i][0]=='H')X5++;
    }
    ll s=0;
    s+=(X*X2*X3);
    s+=(X*X2*X4);
    s+=(X*X2*X5);
    s+=(X*X4*X3);
    s+=(X*X5*X3);
    s+=(X*X4*X5);
    s+=(X2*X4*X3);
    s+=(X2*X5*X3);
    s+=(X2*X4*X5);
    s+=(X3*X4*X5);
    //if(X+X2+X3+X4+X5<3)cout<<0;
    cout<<s;
}
