#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int a[3],k;
  cin >> a[0] >> a[1] >> a[2] >> k;
  
  sort(a,a+3);
  while(k > 0){
    a[2] *= 2;
    k--;
  }
  
  cout << a[0] + a[1] + a[2] << endl;
  
}