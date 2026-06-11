#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll N,K,ans=0;
  cin >> N >> K;
  if(K%2==1) ans = pow(ll(N/K),3);
  else{
    ll tmp1 = K/2;
    ll tmp2=1,cnt=0;
    while(tmp1*tmp2<=N){
      tmp2+=2;
      cnt++;
    }
    ans = pow(cnt,3)+pow(ll(N/K),3);
  }
  cout << ans << endl;
}