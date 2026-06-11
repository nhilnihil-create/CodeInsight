#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  long long A, B;
  cin >> A >> B;
  vector<long long> twoEx(41);
  twoEx[0] = 2;
  for(int i = 1; i < 41; i++){
    twoEx[i] = twoEx[i-1] * 2;
  }
  bitset<40> ans;
  bitset<40> a(A);
  bitset<40> b(B);
  if((B - A + 1) % 2 == 0){
    ans.set(0, (B-A+1)%4);
  } else{
    if(A % 2 == 0){
      ans.set(0, (B-A+1)/2%2);
    } else{
      ans.set(0, (B-A+2)/2%2);
    }
  }
  a >>= 1;
  b >>= 1;
  for(int i = 1; i < 40; i++){
    long long x = 0, y = 0;
    if(a[0]){
      x = ((A / twoEx[i] + 1) * twoEx[i]) - A;
    }
    if(b[0]){
      y = B % twoEx[i] + 1;
    }
    ans.set(i, (x + y) % 2);
    a >>= 1;
    b >>= 1;
  }
  cout << ans.to_ullong() <<endl;
}