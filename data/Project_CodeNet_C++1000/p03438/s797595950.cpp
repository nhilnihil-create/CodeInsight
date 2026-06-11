#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,a=0,m=0,n=0;
  cin >> N;
  vector<ll> A(N),B(N);
  rep(i,N){
    cin >> A.at(i);
  }
  rep(i,N){
    cin >> B.at(i);
    a+=A.at(i)-B.at(i);
    if(A.at(i)>B.at(i)){
      m+=A.at(i)-B.at(i);
    }else{
      n+=(B.at(i)-A.at(i)+1)/2;
    }
  }
  if(a>0||m>-a||n>-a){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}
