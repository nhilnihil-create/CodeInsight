#include <bits/stdc++.h>
using namespace std;

int main(){
  string n;
  cin >> n;
  if (n[1] == n[2]) {
      if(n[1] == n[0] || n[2] == n[3]) cout << "Yes" << endl;
      else cout << "No" << endl;
  }
  else cout << "No" << endl;
    return 0;
}