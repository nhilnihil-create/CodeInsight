#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main() {
  vector<vector<int>> a(3,vector<int>(3));
  rep(i,3)rep(j,3) cin>>a[i][j];
  vector<int> x(3);
  vector<int> y(3);
  x[0]=0;
  rep(i,3) y[i]=a[0][i]-x[0];
  rep(i,3) x[i]=a[i][0]-y[0];
  bool good=true;
  rep(i,3)rep(j,3){
    if(x[i]+y[j]!=a[i][j]){
      good=false;
    }
  }
  if(good){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}