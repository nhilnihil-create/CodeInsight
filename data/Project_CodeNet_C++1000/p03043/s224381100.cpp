#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  cout<<setprecision(10)<<fixed;
  int n,k; cin>>n>>k;
  double ans=0;
  for(int d=1; d<=n; d++){//d:dice
    int now=d;
    double coin=1;
    while(now<k){
      now*=2;
      coin*=(double)1/2;
    }
    ans+=coin;
  }
  double p=1/(double)n;
  ans*=p;
  cout<<ans<<endl;
}

