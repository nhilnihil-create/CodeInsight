#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int a,b,ans;
  cin >> a >> b;
  ans += a-1;
  if(a <= b) ans++;
  cout << ans << endl;
}