#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b;cin >> a >> b;
  string s; cin >> s;
  bool ok = true;
  int n = s.size();
  ok &= n == (a + b + 1);
  for(int i = 0; i < n; i++){
    if(i == a) ok &= s[i] == '-';
    else{
      int t = s[i] - '0';
      ok &= (t <= 9) && (t >= 0);
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}
  