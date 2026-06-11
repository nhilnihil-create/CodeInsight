#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll sub(ll a){
  if (a % 4 == 0) return a;
  else if (a % 4 == 1) return (a-1) ^ a;
  else if (a % 4 == 2) return (a-2) ^ (a-1) ^ a;
  else if (a % 4 == 3) return 0ll;
}

int main(){
  ll a, b; cin >> a >> b;
  cout << ( sub(max(0ll,--a)) ^ sub(b) ) << endl;
}