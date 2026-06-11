#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int h,w;
  cin>>h>>w;
  char c[h][w];
  rep(i,0,h){
    rep(j,0,w){
      cin>>c[i][j];
    }
  }
  int dx[4]={1,0,-1,0};
  int dy[4]={0,1,0,-1};
  bool p=true;
  rep(i,0,h){
    rep(j,0,w){
      if(c[i][j]=='#'){
        bool q=false;
        rep(k,0,4){
          if(i+dx[k]>=0 && i+dx[k]<h && j+dy[k]>=0 && j+dy[k]<w){
            if(c[i+dx[k]][j+dy[k]]=='#'){
              q=true;
            }
          }
        }
        if(!q){
          p=false;
        }
      }
    }
  }
  if(p) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}