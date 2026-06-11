#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,s;
  cin >> N;
  cin >> A;
  
  s = N%500;
  if(s>A) cout << "No" << endl;
  else cout << "Yes" << endl;
  
}