#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

int
main() 
{
  ll N, K; cin >> N >> K;
  
  if(K % 2 == 1){
    ll mul_num = N / K;
    cout << mul_num * mul_num * mul_num << endl;
    return 0;
  }

  ll ans = 0;
  ll mul_num = N / K;
  repe(i, 0, N){
    if(i % K == K / 2) ans++;
  }
  cout << mul_num * mul_num * mul_num + ans * ans * ans << endl;

}


