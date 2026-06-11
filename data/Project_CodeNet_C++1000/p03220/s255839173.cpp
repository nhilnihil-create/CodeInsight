#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int N,T,A;
  cin>>N>>T>>A;
  int H[N];
  rep(i,N) cin >> H[i];
  int ans, n;
  int d = 1e9;
  rep(i,N){
    n = abs(1000*A-(1000*T-H[i]*6));
    if (d > n){
      ans = i+1;
      d = n;
    }
  }
  cout << ans << endl;
}