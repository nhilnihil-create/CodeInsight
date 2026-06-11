#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A, B;
  cin >> A >> B;
  int sum = 0;
  
  for ( int cnt = A; cnt <= B; ++cnt ) {
    int tmp = cnt; 
    int x = 0;
    x += (tmp % 10) * 10000; tmp /= 10;
    x += (tmp % 10) * 1000;  tmp /= 10;
    x += (tmp % 10) * 100;   tmp /= 10;
    x += (tmp % 10) * 10;    tmp /= 10;
    x += (tmp % 10) * 1;     tmp /= 10;
    
    if ( x == cnt ) sum++;
  }
  
  cout << sum << endl;
}