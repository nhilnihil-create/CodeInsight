#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  
  int sum = 700;
  
  rep(i,3) {
    char a;
    cin >> a;
    if (a == 'o') sum += 100;
  }
  
  cout << sum << endl;
  
}
