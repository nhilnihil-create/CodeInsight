#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    if (i >= a.size() - 8) {
      a[i] = ' ';
    }
  }
  cout << a;
}