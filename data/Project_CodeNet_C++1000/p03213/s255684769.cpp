#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

vll v;

//N!の素因数分解
vll prime_fact(int N){
  vll v(N+1,0);
  for(int i=2;i<=N;++i){
    int tmp = i;
    for(int j=2;j<=i;++j){
      while(tmp%j==0){
        tmp/=j;
        v[j]++;
      }
    }
  }
  return v;
}

ll num(ll a){
  ll tmp=0;
  rep(i,v.size()){
    if(v[i]>=a-1) tmp++;
  }
  return tmp;
}

int main(){
  ll N;cin>>N;
  v = prime_fact(N);
  
  cout << (num(75) + num(25) * (num(3) - 1) + \
  num(15) * (num(5) - 1) + num(5) * (num(5) - 1) * (num(3) - 2) / 2) << endl;
}