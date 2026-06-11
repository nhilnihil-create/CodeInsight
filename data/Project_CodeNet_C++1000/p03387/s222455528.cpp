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

int main() {
  vector<int> a(3);
  rep(i,3) cin>>a[i];
  sort(all(a));
  reverse(all(a));
  int ans=0;
  if(a[0]!=a[1]&&a[1]!=a[2]&&a[2]!=a[0]){
    ans+=a[0]-a[1];
    a[2]+=a[0]-a[1];
    a[1]=a[0];
  }
  if(a[0]==a[1]&&a[0]!=a[2]){
    if((a[0]-a[2])%2==0){
      ans+=(a[0]-a[2])/2;
      cout<<ans<<endl;
      return 0;
    }
    if((a[0]-a[2])%2==1){
      ans+=(a[0]-a[2])/2+2;
      cout<<ans<<endl;
      return 0;
    }
  }
  if(a[0]!=a[1]&&a[1]==a[2]){
      cout<<a[0]-a[1]<<endl;
      return 0;
  }
  if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[0]){
    cout<<0<<endl;
    return 0;
  }
}