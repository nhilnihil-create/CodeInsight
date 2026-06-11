#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >> N >> A >> B;
  
  string x;
  
  if((B-A)%2==0) x="Alice";
  else if((B-A)%2==1) x="Borys";
  
  cout << x <<endl;
}
