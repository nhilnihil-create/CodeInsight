#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  for(ll i=0;i<N;++i){
    cin >> A[i];
  }
  ll tmp,cnt1=0,cnt2=0,tmp2=0;
  for(ll i=0;i<N;++i){
    if(A[i]==1){
      tmp=i;
      break;
    }
  }
  while(tmp+cnt1*(K-1)<N-1){
    cnt1++;
  }
  tmp2 = tmp+cnt1*(K-1)-N+1;
  while(tmp-tmp2-cnt2*(K-1)>0){
    cnt2++;
  }
  cout << cnt1+cnt2 << endl;
}