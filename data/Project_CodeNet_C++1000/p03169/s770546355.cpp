#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
double n;
double dp[330][330][330];//1 ,2 3  x通り
int main() {
 cin>>n;
 vin a(n);
  int x=0,y=0,z=0;
  rep(i,0,n){
  cin>>a[i];
   if(a[i]==1) x++;
   else if(a[i]==2) y++;
   else z++;
 }
  ////////////
  dp[0][0][0]=0;
  rep(k,0,n+1){
   rep(j,0,n+1){
     rep(i,0,n+1){         
      if(i+j+k==0) continue; 
       
       dp[i][j][k]=double(n/(i+j+k));
      if(i-1>=0) dp[i][j][k]+=dp[i-1][j][k]*i/(i+j+k);
      if(j-1>=0) dp[i][j][k]+=dp[i+1][j-1][k]*j/(i+j+k);
      if(k-1>=0) dp[i][j][k]+=dp[i][j+1][k-1]*k/(i+j+k);
     }
   }    
  }
  cout<<fixed<<setprecision(10);
  cout<<dp[x][y][z]<<endl;
}







