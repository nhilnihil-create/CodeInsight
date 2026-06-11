#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll a,b;
  cin >> a >> b;
  int res = 0;
  while(a <= b){
    res += 1;
    a *= 2;
  }
  cout << res;
}