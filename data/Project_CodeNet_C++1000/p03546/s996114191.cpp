#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const double EPS = 1e-10;

const int v=10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    int d[v][v];
    for(int i=0;i<v;i++)for(int j=0;j<v;j++){
        if(i==j)d[i][j]=0;
        else d[i][j]=INF;
    }
    int c[v][v];
    for(int i=0;i<v;i++)for(int j=0;j<v;j++){
        cin>>c[i][j];
        d[i][j]=min(d[i][j],c[i][j]);
    }
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int ans=0;
    for(int i=0,a;i<h;i++)for(int j=0;j<w;j++){
        cin>>a;
        if(a==-1)continue;
        ans+=d[a][1];
    }
    cout<<ans<<endl;
}