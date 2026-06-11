#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int ans=0;
  ans += min( a,b );
  ans += min( c,d );
  cout << ans << endl;
  
  return 0;
}