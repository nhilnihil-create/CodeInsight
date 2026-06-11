#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int diff = abs(a-b-1);
  if(diff % 2 == 1) cout << "Alice" << endl;
  else cout << "Borys" << endl;
}