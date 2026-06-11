#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(int i=0;i<n;i++)
using Graph = vector<vector<int>>;
using pint = pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
    int h,w,d;cin>>h>>w>>d;
    int g[h][w];
    pint number[h*w+1]={};
    rep(i,h){
        rep(j,w){
            cin>>g[i][j];
            number[g[i][j]]=(make_pair(i,j));
        }
    }
    int dist[h*w+1]={};
    for(int i=d+1;i<h*w+1;i++){
        dist[i]=dist[i-d]+abs(number[i].first-number[i-d].first)+abs(number[i].second-number[i-d].second);
    }
    int q;cin>>q;
    pint lr[q]={};
    rep(i,q) cin>>lr[i].first>>lr[i].second;
    rep(i,q){
        int ans=dist[lr[i].second]-dist[lr[i].first];
        cout<<ans<<"\n";
    }
}
