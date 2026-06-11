#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,M;
  cin >> N >> M;
  vector<ll> X(N);
  vector<ll> Y(N);
  vector<ll> Z(N);
  for(int i=0;i<N;i++){
    cin >> X[i] >> Y[i] >> Z[i];
  }
  ll score = 0;
  for(int bit=0;bit<(1<<3);bit++){
    ll a=1,b=1,c=1;
    vector<ll> S(N);
    if(bit&(1<<0)){
      a = -1;
    }
    if(bit&(1<<1)){
      b = -1;
    }
    if(bit&(1<<2)){
      c = -1;
    }
    //cout << bit << " " << a << " " << b << " " << c << endl;
    for(int i=0;i<N;i++){
      S[i] = a*X[i] + b*Y[i] + c*Z[i];
    }
    sort(S.begin(),S.end());
    reverse(S.begin(),S.end());
    ll sum = 0;
    for(int i=0;i<M;i++){
      sum += S[i];
    }
    score = max(score,sum);
  }
  cout << score << endl;
}