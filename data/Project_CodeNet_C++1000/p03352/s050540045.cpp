#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int ans, maxans = 1;
  for(int i = 2; i * i <= n; i++){
    ans = i;
    while(ans * i <= n){
      ans = ans * i;
    }
    if(ans > maxans){
      maxans = ans;
    }
  }
  
  cout << maxans << endl;
}