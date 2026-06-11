#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  ll N,K,M,sum = 0; cin >> N >> K >> M;
  if(K/N >= M){
    cout << M;
  }
  else{
    cout << K/N;
  }
}