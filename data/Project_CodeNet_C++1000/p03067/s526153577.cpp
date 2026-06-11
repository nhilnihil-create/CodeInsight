#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define intput(i) cout << i << endl
#define ll long long
#define stringput(s) cout << (string)(s) << endl

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  string ans;
  if(a > b){
    if(c > b && a > c) ans = "Yes";
    else ans = "No";
  }
  else{
    if(c < b && a < c) ans = "Yes";
    else ans = "No";
  }
  cout << ans << endl;
}
