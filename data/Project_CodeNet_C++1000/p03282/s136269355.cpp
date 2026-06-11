#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  string s;
  ll k;
  cin >> s;
  cin >> k;
  int num;
  for(int i=0;i<k;i++){
    if((s.at(i))!='1'){
      cout << s.at(i) << endl;
      return 0;
    }
  }
  cout << 1 << endl;
}


