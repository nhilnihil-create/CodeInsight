#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {

  int a;
  cin >> a;
  
  if(a%111 == 0) cout << a << endl;
  else cout << a + 111 - a%111 << endl; 
  
  
  
}
