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
int INF=100100100;

signed main(){
  int n;cin>>n;
  int ans=0;
  for(int i=1;i*i<=n;i++){
    if(n%i!=0)continue;
    int m=n/i-1;
    if(m>INF|| m*m+m>n){
      ans+=m;
      //cout<<m<<endl;
    }
  }
  cout<<ans<<endl;
  return 0;
}