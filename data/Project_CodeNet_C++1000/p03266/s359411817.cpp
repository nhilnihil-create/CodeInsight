#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,k;
  cin >> n >> k;
  if(k %2 == 1){
    ll a = n/k;
    cout << a*a*a << endl;
  }else{
    ll a = n/k;
    ll b = (n + (k/2))/k;
    cout << a*a*a + b*b*b <<endl;
  }
  return 0;
}
