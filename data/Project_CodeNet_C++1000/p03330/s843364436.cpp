#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n,c;
  cin>>n>>c;
  vector<vector<int>> a(c,vector<int>(c));
  rep(i,c) {
    rep(j,c){
      cin >> a.at(i).at(j);
    }
  }
  vector<vector<int>> b(n,vector<int>(n));
  vector<vector<int>> d(c,vector<int>(3));
  rep(i,n) {
    rep(j,n){
      cin >> b.at(i).at(j);
      b.at(i).at(j)--;
      d[b.at(i).at(j)][(i+j)%3]++;
    }
  }
  int ans=1001001001;
  rep(i,c){
    rep(j,c){
      rep(k,c){
        if(i!=j&&j!=k&&k!=i){
          int now=0;
          rep(x,c){
            now+=d[x][0]*a[x][i];
            now+=d[x][1]*a[x][j];
            now+=d[x][2]*a[x][k];
          }
          ans=min(ans,now);
        }
      }
    }
  }
  cout<<ans<<endl;  
}

