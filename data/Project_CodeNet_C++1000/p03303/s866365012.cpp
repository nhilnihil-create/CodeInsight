#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll w,i=0;
  string S;
  cin >> S >> w;
  while(i<S.size()){
    cout << S.at(i);
    i+=w;
  }
  cout << endl;
  
}
