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
  string S, T; cin >> S >> T;
  
  rep(i,110){
    S.insert(S.begin(), S[S.size()-1]);
    S.pop_back();
    if(S ==T){ cout <<"Yes"<< endl; return 0;}
  }
  cout <<"No"<< endl;
  return 0;
}