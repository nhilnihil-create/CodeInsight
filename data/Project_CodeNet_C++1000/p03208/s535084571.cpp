#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
  ll N ,K;
  cin >> N >> K;
  vector<ll>H(N);
  
  rep(i,N)cin >> H[i];
  
  sort(H.begin(),H.end());
  
  ll mina = 1000000010;
  ll now = 0;
  
  for(int i = 0; i < N-K+1; i++){
    now = H[i+K -1] - H[i];
    mina = min(now,mina);

  }
  
  cout << mina << endl;
  return 0;
  
}