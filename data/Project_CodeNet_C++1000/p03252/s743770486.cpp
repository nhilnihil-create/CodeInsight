#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000;
#define all(v) v.begin(), v.end()

int main(){
  string S,T;
  cin >> S >> T;
  vector<ll> A(26);
  rep(i,S.size()){
    if(A.at(S.at(i)-'a')!=T.at(i)){
      if(A.at(S.at(i)-'a')==0){
        A.at(S.at(i)-'a')=T.at(i);
      }else{
        cout << "No" << endl;
        return 0;
      }
    }
  }
  rep(i,26){
    for(ll j=i+1;j<26;j++){
      if(A.at(i)==A.at(j)&&A.at(i)!=0){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
    
    
}