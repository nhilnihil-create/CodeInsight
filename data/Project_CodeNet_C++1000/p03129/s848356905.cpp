#include<iostream>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  if(n % 2 == 1 && k <= (n + 1) / 2) cout << "YES";
  else if(n % 2 == 0 && k <= n / 2) cout << "YES";
  else cout << "NO";
  return 0;
}