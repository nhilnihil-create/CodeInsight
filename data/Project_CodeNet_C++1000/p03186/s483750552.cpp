#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int ans=0;
  ans+=b;
  int T=min(b+1,c);
  ans+=T;
  c-=T;
  ans+=min(a,c);
  cout << ans << endl;
  return 0;
}