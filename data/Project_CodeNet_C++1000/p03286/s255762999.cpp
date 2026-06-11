#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll S;
  cin >> S;
  if (S == 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<bool> V(32,false);
  for (ll i = 0; i < 32; i++){
    ll hoge = pow(2,i);
    if (S % (hoge * 2) != 0) {
      V.at(i) = true;
      if (i % 2 == 0) S -= hoge;
      else S += hoge;
    }
  }
  bool h = false;
  for (int i = 31; i >= 0; i--) {
    if (V.at(i)) {
      h = true;
      cout << 1;
    }
    else if (h) {
      cout << 0;
    }
  }
  cout << endl;
}