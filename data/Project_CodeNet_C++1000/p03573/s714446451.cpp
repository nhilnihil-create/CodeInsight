#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a[3];
  rep(i,3) {
    cin >> a[i];
  }

  if(a[0] == a[1]) cout << a[2] << endl;
  else if(a[0] == a[2]) cout << a[1] << endl;
  else cout << a[0] << endl;
  
  return 0;
}
