#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  double n,k;
  cin >> n >> k;
  double ans=0.0;
  for(double i=1.0;i<=n;i++){
    if(i>=k)
    ans=ans+1.0;
    else{
      for(double j=1.0;j<20.0;j++){
        if(i*pow(2,j)>=k){
          ans=ans+1.0/(pow(2,j));
          break;
        }
      }
    }
  }
  cout << fixed << setprecision(10) << ans/n << endl;
}

