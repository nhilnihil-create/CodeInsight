#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a[4];
  rep(i, 4){
    cin >> a[i];
  }

  cout << min(a[0],a[1]) + min(a[2],a[3]) << endl;
  
  return 0;
}
