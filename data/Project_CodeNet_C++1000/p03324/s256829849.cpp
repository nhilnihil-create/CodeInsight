#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
 
int main() {
  int d,n;
  cin >> d >> n;
  int s = 1; for (int i = 0; i < d; i++) s *= 100;
  if(n <= 99){
    cout << s * n << endl;
  }
  else{
    cout << s * 101 << endl;
  } 
  return 0;
}