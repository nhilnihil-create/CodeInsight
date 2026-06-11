#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,pair<int,int> > P;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXH=500;
const int MAXW=500;
const ll INF=1e9;

struct edge{
    int to;
    ll cost;
};

int main(){
    int h,w;cin>>h>>w;
    vector<vector<int> > c(10,vector<int>(10));
    vector<vector<int> > a(h,vector<int>(w));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>c[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    for(int k=0;k<10;k++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]==-1) continue;
            ans+=c[a[i][j]][1];
        }
    }
    cout<<ans<<endl;
    return 0;
}