#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;


int n,m;

int dk[N];
int vis[N],p[10][10],a[300][300];

void dj(int x)
{
    vis[x]=1;
    for(int i=0;i<=9;i++) dk[i]=p[x][i];

    for(int i=0;i<9;i++){
        int minn=10000,pos;
        for(int j=0;j<=9;j++){
            if(!vis[j] && minn>dk[j]){
                minn=dk[j];
                pos=j;
            }
        }
        vis[pos]=1;
        for(int j=0;j<=9;j++){
            if(dk[pos]+p[pos][j]<dk[j] && !vis[j])
                 dk[j]=dk[pos]+p[pos][j];
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            cin>>p[i][j];
        }
    }
    for(int i=0;i<=9;i++){
        for(int j=i;j<=9;j++){
            swap(p[i][j],p[j][i]);
        }
    }
    dj(1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]!=-1) ans+=dk[a[i][j]];
        }
    }
  //  cout<<vis[1]<<endl;
    cout<<ans<<endl;
    return 0;
}
