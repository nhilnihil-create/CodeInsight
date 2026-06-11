#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<char>> t(h,vector<char>(w));
  rep(i,h)rep(j,w) cin>>t[i][j];
  rep(i,h)rep(j,w){
    if(t[i][j]=='#') continue;
    if(t[i][j]=='.'){
      int cnt=0;
      for(int k=i-1;k<=i+1;k++){
        for(int l=j-1;l<=j+1;l++){
          if(k<0||k>=h||l<0||l>=w) continue;
          if(t[k][l]=='#') cnt++;
        }
      }
      t[i][j]='0'+cnt;
    }
  }
  rep(i,h){
    rep(j,w){
      cout<<t[i][j];
    }
    cout<<endl;
  }
}
