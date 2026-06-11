#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long X, Y;
  cin >> X >> Y;

  long long ans=0;
  while(X <= Y){
    X *= 2;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
