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
  int n;
  cin>>n;
  vector<vector<int>> c(2,vector<int>(n));
  rep(i,2) rep(j,n) cin>>c[i][j];
  int ans=0;
  rep(i,n){
    int cnt=0;
    for(int j=0;j<=i;j++){
      cnt+=c[0][j];
    }
    for(int j=i;j<n;j++){
      cnt+=c[1][j];
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}