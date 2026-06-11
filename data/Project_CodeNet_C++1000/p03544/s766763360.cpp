#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  ll l0 = 2, l1 = 1;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  
  ll l = 0;
  for(int i = 2; i <= n; i++){
    l = l0 + l1;
    l0 = l1;
    l1 = l; 
  }
  
  cout << l << endl;
}
