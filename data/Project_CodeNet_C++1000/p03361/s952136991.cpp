#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<char>> c(h,vector<char>(w));
  rep(i,h)rep(j,w) cin>>c[i][j];
  rep(i,h){
    rep(j,w){
      if(c[i][j]=='#'){
        bool ja=true;
        rep(k,4){
          if(i+di[k]<0||i+di[k]>=h||j+dj[k]<0||j+dj[k]>=w) continue;
          if(c[i+di[k]][j+dj[k]]=='#') ja=false;
        }
        if(ja){
          cout<<"No"<<endl;
          return 0;
        }
      }
    }
  }
  cout<<"Yes"<<endl;
}