#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
  int a,b,k;
  cin >> a >> b >> k;
  
  int n = min(a,b);
  int x[n] = {0};
  int j = 0;
  for(int i = 1; i <= n; i++){
    if(a % i == 0 && b % i == 0){
      x[j] = i;
      j++;
    }
  }
  
  sort(x,n+x,greater<int>());
  int ans = x[k-1];
  cout << ans << endl;
}