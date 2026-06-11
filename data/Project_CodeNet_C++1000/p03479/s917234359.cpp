#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int main(){
  ll x,y;
  cin >> x >> y;
  
  ll ans = 0;
  ll nx = x;
  while(nx <= y){
    nx *= 2;
    ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}