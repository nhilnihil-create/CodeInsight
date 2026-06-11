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
  int n,m,c;
  cin>>n>>m>>c;
  vector<int> b(m);
  int ans=0;
  int cnt=0;
  vector<vector<int>> a(n,vector<int>(m));
  rep(i,m) cin>>b[i];
  rep(i,n)rep(j,m) cin>>a[i][j];
  rep(i,n){
    cnt=0;
    rep(j,m){
      cnt+=a[i][j]*b[j];
    }
    cnt+=c;//cnt+c;
    if(cnt>0) ans++;//ans=ans+1;
  }
  cout<<ans<<endl;
}
