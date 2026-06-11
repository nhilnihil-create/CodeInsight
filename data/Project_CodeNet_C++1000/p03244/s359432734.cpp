#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,x=0,y=0,b,z=0,z2=0;
    cin>>n;
    ll l1[n+2];map<ll,ll>m1,m2;
    //cin>>l1[1]>>l1[2];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        if(i&1){
            m1[l1[i]]++;
            if(m1[l1[i]]>x)x=m1[l1[i]],a=l1[i];
        }
        else{
            m2[l1[i]]++;
            if(m2[l1[i]]>y)y=m2[l1[i]],b=l1[i];
        }
    }
    if(a==b&&x>y){
        for(int i=2;i<=n;i+=2){
            if(l1[i]!=b)z=max(z,m2[l1[i]]);
        }n/=2;
        cout<<(n-x)+(n-z)<<endl;
    }
    else if(a==b&&x==y){
        for(int i=2;i<=n;i+=2){
            if(l1[i]!=b)z=max(z,m2[l1[i]]);
        }
        for(int i=1;i<=n;i+=2){
            if(l1[i]!=a)z2=max(z2,m1[l1[i]]);
        }n/=2;
        if(z>=z2)cout<<(n-z)+(n-x)<<endl;
        else cout<<(n-z2)+(n-x)<<endl;
    }
    else if(a==b&&x<y){
        for(int i=1;i<=n;i+=2){
            if(l1[i]!=a)z=max(z,m1[l1[i]]);
        }n/=2;
        cout<<(n-y)+(n-z)<<endl;
    }
    else {n/=2;cout<<(n-x)+(n-y)<<endl;}
}
