#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;

  int ans = 0;
  rep(i,n+1){
    int j = 0;
    int cnt = 0;
    while(j < n){
      j++;
      if(j%2 == 0) continue;
      if(i%j == 0) cnt++;
    }
    if(cnt == 8) ans++;
  }
  cout << ans << endl;

}
