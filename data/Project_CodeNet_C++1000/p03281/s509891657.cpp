#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1e18;

int main(){
  int n;
  cin >> n;

  int ans = 0;
  for(int i = 1; i<=n; i+=2){
    int div = 0;
    for(int j = 1; j<=i; j++){
      if(i%j==0) div++;
    }
    if(div==8) ans++;
  }

  cout << ans << endl;

  return 0;
}