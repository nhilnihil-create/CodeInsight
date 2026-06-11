#include<bits/stdc++.h>
using namespace std;
int main(){
  int ans=0,a,b;
  cin >> a >> b;
  ans=max(a+b,a+a-1);
  ans=max(ans,b+b-1);
  cout << ans << endl;
}