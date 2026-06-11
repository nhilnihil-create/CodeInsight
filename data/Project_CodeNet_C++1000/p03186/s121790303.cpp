#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;


int main(){
  int a,b,c;
  int64_t ans;
  cin >> a >> b >> c;
  if(a+b>=c)ans = b+c;
  else if(b>=c)ans = b+c;
  else ans = a+2*b+1;  
  cout << ans;
}


