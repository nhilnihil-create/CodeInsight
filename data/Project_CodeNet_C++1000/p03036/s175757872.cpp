#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll r,d,x_2000;
  cin>>r>>d>>x_2000;
  for(ll i=0;i<10;i++){
    x_2000=r*x_2000-d;
    cout<<x_2000<<endl;
  }
  return 0;
}
