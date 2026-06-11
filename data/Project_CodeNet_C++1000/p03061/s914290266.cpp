#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll v[n+1],x=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    ll l[n+2],r[n+2];
    for(int i=1;i<=n;i++){
        if(i==1)l[i]=v[i];
        else l[i]=__gcd(v[i],l[i-1]);
        if(n-i+1==n)r[n-i+1]=v[n-i+1];
        else r[n-i+1]=__gcd(v[n-i+1],r[n-i+2]);
    }
    for(int i=1;i<=n;i++){
        if(i==1)x=max(x,r[i+1]);
        else if(i==n)x=max(x,l[i-1]);
        else x=max(x,__gcd(l[i-1],r[i+1]));
    }
    cout<<x;
}
