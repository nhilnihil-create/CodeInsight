#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,beg=0;
  cin >> N >> K;
  int num0=N-1;
  long long x[N],ans=100000000001;
  for(int i=0; i<N; i++) cin >> x[i];
  for(int i=0; i<N; i++) if(x[i]>0){
     num0 = i-1;
     break;
   }
  for(int i=max(num0-K+1,0); i<min(N-K+1,num0+2); i++){
    ans = min(ans, 2*llabs(x[i])+llabs(x[i+K-1]));
    ans = min(ans, 2*llabs(x[i+K-1])+llabs(x[i]));
    if(x[i]*x[i+K-1]>=0) ans = min(ans, max(llabs(x[i]),llabs(x[i+K-1])));
  }
  cout << ans << endl;
  return 0;
}
