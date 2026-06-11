#include "bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define all(a) a.begin(),a.end()
typedef pair<int,int> P;
const long long mod=1000000007;
const long long inf=1ll<<61;

signed main(){
  int n,k;cin>>n>>k;
  double ans=0;
  for(int i=1;i<=n;i++){
    double per=1.0/(double)n;
    int now=i;
    while(now<k){
      now*=2;
      per/=2.0;
    }
    ans+=per;
  }
  cout<<fixed<<setprecision(13)<<ans<<endl;
}