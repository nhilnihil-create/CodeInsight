#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll N,a,b;
  cin >> N;
  vector<ll> X(N),Y(N);
  rep(i,N) {
    cin>> X.at(i);
    Y.at(i)=X.at(i);
  }
  sort(all(Y));
  a=Y.at(N/2-1);
  b=Y.at(N/2);
  rep(i,N){
    if(X.at(i)<=a){
      cout << b << endl;
    }else{
      cout << a << endl;
    }
  }
  
  
}
  