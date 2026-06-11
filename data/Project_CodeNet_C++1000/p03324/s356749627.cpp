#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int d,n;
  cin >> d >> n;
 
  if(n == 100){
    n = 101;
  }
  if(d == 0){
    cout << n << endl;
    return 0;
  }else if(d == 1){
    cout << n * 100 << endl;
  }else if(d == 2){
    cout << n * 100 * 100 << endl;
  }
}