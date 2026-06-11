#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int sum = [=]()mutable{
    int res = 0;
    while(n > 0) {
      res += n%10;
      n /= 10;
    }
    return res;
  }();
  cout << (n%sum == 0 ? "Yes" : "No") << endl;
}