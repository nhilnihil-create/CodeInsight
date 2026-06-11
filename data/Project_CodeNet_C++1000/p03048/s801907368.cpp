#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int r,g,b,n;cin>>r>>g>>b>>n;
  int ans=0;
  for(int i=0;i<=n;i+=r){
    for(int j=0;j<=n;j+=g){
      if(n-i-j>=0 && (n-i-j)%b==0)ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}