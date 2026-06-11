#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int a, b;
  cin >> a >> b;
  if(a % 2 == 1 && b % 2 == 1){
    cout << "Odd";
  }
  else{
    cout << "Even";
  }
  return 0;
}


