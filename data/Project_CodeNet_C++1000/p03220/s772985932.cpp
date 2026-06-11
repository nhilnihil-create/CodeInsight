#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  double t,a;
  cin>>n>>t>>a;
  
  vector<double> H(n);
  double x;
  rep(i,n){
    cin>>x;
    H[i]=abs(t-x*0.006-a);
  }
  
  double mi=1e9;
  int ans;
  rep(i,n){
    if(mi>H[i]){
      mi=H[i];
      ans=i;
    }
  }

  cout<<ans+1<<endl;
  
  return 0;
}