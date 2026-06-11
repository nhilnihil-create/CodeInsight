#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
 
int main()
{
    int n,m,x,y,i,j; cin>>n>>m>>x>>y;
    int a[n],b[m];
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<m;i++) cin>>b[i];
    sort(a,a+n); sort(b,b+m);
    bool f=true;
    if(a[n-1]>=b[0]) f=false;
    int z=min(y,b[0]);
    if(z<=x || z<=a[n-1]) f=false;
    cout<<(f ? "No War" : "War");
}