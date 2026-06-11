#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,a=0,b=INF,t=0;
  cin >> N;
  vector<ll> A(N),B(N);
  rep(i,N){
    cin >> A.at(i) >> B.at(i);
    if(A.at(i)!=B.at(i)) t=1;
    a+=A.at(i);
    if(A.at(i)>B.at(i))b=min(b,B.at(i));
  }
  if(t==0){
    cout << 0 << endl;
  }else{
    cout << a-b << endl;
  }
}