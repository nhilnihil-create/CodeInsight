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
  const string key = "keyence";
  string S; cin >> S;
  int k = S.size()-7;
  if (k == 0 && S == key) {cout << "YES" << endl; return 0;} 
  
  for(int i=0; i < S.size()-k+1 ; i++){
    string ans;
    ans = S.substr(0,i)+S.substr(i+k);
    if(ans == key) {cout << "YES" << endl; return 0;}
  }
  cout << "NO" << endl;
  return 0;
}
