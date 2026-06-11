#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define intput(i) cout << i << endl
#define ll long long
#define stringput(s) cout << (string)(s) << endl

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string ans = "No";
  if(abs(a-c) <= d) ans = "Yes";
  else if(abs(a-b) <= d && abs(b-c) <= d) ans = "Yes";
  cout << ans << endl;
}
