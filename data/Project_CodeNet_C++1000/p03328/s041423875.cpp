#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {

  int a,b;
  cin >> a >> b;
  
  int x = b-a;
  int sum = 0;
  
  rep(i,x) sum += i;
  
  cout << sum-a << endl;
  
  
}
