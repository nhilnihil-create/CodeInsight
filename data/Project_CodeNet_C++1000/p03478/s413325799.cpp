#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n,a,b;
  cin >> n >> a >> b;
  
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int x = i;
    int sum = 0;
    while(x > 0){
      sum += x % 10;
      x /= 10;
    }
    if(sum >= a && sum <= b){
      ans += i;
    }
  }
  
  cout << ans << endl;
      
}
