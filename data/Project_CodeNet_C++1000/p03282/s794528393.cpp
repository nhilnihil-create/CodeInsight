#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s;
  ll k;
  cin >>s >>k;
  for(ll i = 0; i<min((ll)s.size(), k); i++){
    if(s[i]>='2') {
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  return 0; 
}
