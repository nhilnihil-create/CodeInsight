#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long n,m,c;

void _case()
{
    cin>>n>>m>>c;
    long long a[n][m],b[m],ans=0,x;
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        x=0;
        for(int j=0;j<m;j++) x+=(a[i][j]*b[j]);
        if(x+c>0) ans++;
    }
    cout<<ans<<'\n';
}

main()
{
    fastio();
    _case();

}


