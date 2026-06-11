#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,a,x,y,c=-2000,d=INT_MAX,e=0;
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        cin>>a;c=max(a,c);
    }c=max(c,x);
    for(int i=1;i<=m;i++){
        cin>>a;
        d=min(a,d);
        e=max(e,a);
    }d=min(y,d);
    if(d<=y&&d>c)cout<<"No War\n";
    else cout<<"War\n";
}
