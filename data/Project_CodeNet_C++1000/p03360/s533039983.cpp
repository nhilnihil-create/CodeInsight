#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {

  int a,b,c,k;
  cin >> a >> b >> c >> k;
  
  int ma = max(a,max(b,c));
  int po = ma * pow(2, k);
  
  cout << a+b+c-ma + po << endl;
  
  
}
