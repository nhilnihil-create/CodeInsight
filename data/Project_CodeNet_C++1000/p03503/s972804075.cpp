#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l1[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,sm=-(1<<30);
    cin>>n;ll f[n+1][11],p[n+1][11];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++)cin>>f[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10;j++)cin>>p[i][j];
    }
    ll b=(1<<10);
    for(int i=1;i<b;i++){ll s=0;
        for(int j=1;j<=n;j++){ll c=0;
            for(int k=9;k>=0;k--)if(((i>>k)&1)&&f[j][10-k])c++;
            s+=p[j][c];
        }
        //cout<<s<<endl;
        sm=max(sm,s);
    }
    cout<<sm<<endl;
}
