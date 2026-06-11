#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
struct Area{
  vector<int> color;
};
signed main(){
  int n,c;cin>>n>>c;
  vector<Area> area(3);
  rep(i,3){
    area[i].color.resize(c+1,0);
  }
  vector<vector<int>> d(c+1,vector<int>(c+1));
  rep1(i,c){
    rep1(j,c){
      cin>>d[i][j];
    }
  }
  rep1(i,n){
    rep1(j,n){
      int buf;cin>>buf;
      area[(i+j)%3].color[buf]++;
    }
  }
  int res=inf;
  rep1(i,c){
    rep1(j,c){
      if(i==j)continue;
      rep1(k,c){
        if(i==k||j==k)continue;
        int buf=0;
        rep1(l,c){
          buf+=d[l][i]*area[0].color[l];
          buf+=d[l][j]*area[1].color[l];
          buf+=d[l][k]*area[2].color[l];
        }
        res=min(buf,res);
      }
    }
  }
  cout<<res<<"\n";
  return 0;
}
