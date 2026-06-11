#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;

int divid10 (int n) {
  int sum = 0;
  while(true){
    if (n/10 == 0){
      sum+=n;
      break;
    }
    sum += n%10;
    n /=10;
  }
  return sum;
}

int main(){

  int n,a,b;
  cin >> n >> a >> b;
  int cnt = 0;
  int sum;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    sum = divid10(i);
    if (sum >= a && sum <= b) ans = ans + i;
  }
  cout << ans << endl;
}

