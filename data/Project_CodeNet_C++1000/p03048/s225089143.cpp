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
  int r,g,b,n;
  cin>>r>>g>>b>>n;
  int ans=0;
  for(int i=0;i<=n/r;i++){
    for(int j=0;j<=n/g;j++){
      if((n-(r*i+g*j))%b==0&&n-(r*i+g*j)>=0) ans++;
    }
  }
  cout<<ans<<endl;
}