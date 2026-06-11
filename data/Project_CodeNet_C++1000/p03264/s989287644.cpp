#include <bits/stdc++.h>
using namespace std;
int main(){
  int k; cin >> k;
  int odd = (k+1)/2, even = k/2;
  cout << odd * even << endl;
  return 0;
}