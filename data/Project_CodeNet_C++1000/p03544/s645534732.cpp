#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll Lucas(ll N,vector<ll> &memo){
  if(memo[N]!=-1){
    return memo[N];
  }
  else{
    memo[N]=Lucas(N-1,memo)+Lucas(N-2,memo);
    return memo[N];
  }
}

int main(){
  ll N;
  cin >> N;
  vector<ll> memo(N+5,-1);
  memo[0]=2;
  memo[1]=1;
  cout << Lucas(N,memo) << endl;
}