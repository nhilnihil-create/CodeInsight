#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;

int main(){
  int N;
  cin >> N;
  LL K;
  cin >> K;
  LL A[100010];
  rep(i,N) cin >> A[i];
  int num[40]={0};
  rep(bit,40){
    rep(j,N) if(A[j]&1LL<<bit) num[bit]++;
  }
  LL X=0, ans=0;
  for(int bit=39; bit>=0; bit--){
    if(X+(1LL<<bit)<=K&&num[bit]*2<N){
      X+=1LL<<bit;
      ans+=(1LL<<bit)*(N-num[bit]);
    }
    else ans+=(1LL<<bit)*num[bit];
  }
  cout << ans << endl;
  
  return 0;
}