#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
  double N,T,A; cin>>N>>T>>A;
  vector<double> H(N);
  rep(i,N) cin>>H[i];
  
  int ans;
  double tem=1e9;
  for(int i=0; i<N; i++){
    if(tem > abs(A-(T-0.006*H[i]))){
      tem = abs(A-(T-0.006*H[i]));
      ans = i;
    }
  }
  
  cerr << A <<endl;
  cout << ans+1 << endl;
}
