#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  
  vector<int> X(n);
  rep(i,n) cin>>X[i];
  
  int mi=1e9;  
  for(int i=0;i+k-1<n;i++){
    if(X[i]>=0) mi=min(mi,X[i+k-1]);
    else if(X[i+k-1]<=0) mi=min(mi,-X[i]);
    else{
      if(X[i+k-1]>=-X[i]) mi=min(mi,-2*X[i]+X[i+k-1]);
      else mi=min(mi,2*X[i+k-1]-X[i]);
    }
  }
  cout<<mi<<endl;

  return 0;
}