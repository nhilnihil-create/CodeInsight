#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll=long long;

long mod=1e9+7;


int main() {
  int n;cin>>n;
  double ans=0;
  rep(i,n){
    double x;string u;cin>>x>>u;
    if(u=="BTC")x*=380000;
    ans+=x;
  }
  cout<<setprecision(10)<<ans<<endl;
}

