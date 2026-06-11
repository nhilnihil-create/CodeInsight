#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int num;
  cin >> num;
  if(num == 0){
    cout << 0 << endl;
    return 0;
  }
  string ans = "";
  while(num != 0){
    int r = num % (-2);
    if(r < 0) r += 2;
    num = (num-r) / (-2);
    ans += (char)('0' + r);
  }
  reverse(all(ans));
  cout << ans << endl;
  return 0;
}
    
  