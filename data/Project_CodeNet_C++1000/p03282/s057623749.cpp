#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  string S; cin >> S;
  ll K; cin >> K;
  
  if(K==1){cout << S[0] << endl; return 0;}
  ll p;
  rep(i, S.size()){
    if(S[i]=='1') continue;
    else {p=i; break;}
  }
  if(K>p) {cout << S[p] << endl; return 0;}
  else {cout << S[0] << endl; return 0;}
  

  return 0;

}