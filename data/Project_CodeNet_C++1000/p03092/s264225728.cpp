#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=5005;
int a[Maxn],pos[Maxn];
ll f[Maxn][Maxn];
int main(){
    int n,A,B;cin>>n>>A>>B;
    for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]]=i;
    memset(f,0x3f,sizeof(f));
    memset(f[0],0,sizeof(f[0]));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            int l=pos[i],delta=0;
            if(l<j)delta=A;
            else if(l>j)delta=B;
            f[i][j]=min(f[i][j],f[i-1][j]+delta);
        }
        for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][j-1]);
    }
    cout<<f[n][n]<<"\n";
    return 0;
}