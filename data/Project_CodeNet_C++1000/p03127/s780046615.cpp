#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  long a,b; cin >> a >> b;
  long ans = gcd(a,b);
  for(int i = 2; i < n; i++){
    long c; cin >> c;
    ans = gcd(ans,c);
  }
  cout << ans;
}