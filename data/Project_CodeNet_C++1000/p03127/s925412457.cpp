#include<iostream>
#include<cmath>
#include <algorithm>  
using namespace std;


int main() {
  int n;
  cin >> n;
  int temp;
  int ans;
  cin >> ans;
  for(int i=1; i < n; i++) {
   	cin >> temp;
    ans = __gcd(ans, temp);
  }
  cout << ans;
  return 0;
}