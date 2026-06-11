#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int a, b, c, k, ans=0;
  cin >> a >> b >> c >> k;
  ans=a-b;
  if(k%2==0){
    cout << ans;
  }
  else cout << -ans;
}
