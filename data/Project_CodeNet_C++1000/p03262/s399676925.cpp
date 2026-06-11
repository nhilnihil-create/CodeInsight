#include <bits/stdc++.h>
using namespace std;

auto gcd(auto x, auto y){
  if(x % y == 0){
    return y;
  }else{
    return gcd(y,x % y);
  }
}

auto lcm(auto x, auto y){
  return x * y / gcd(x,y);
}

int main() {
  long long num,x;
  long long tmp = 0;
  cin >> num >> x;
  
  vector<long long> vec(num);
  for(int i = 0; i < num; i++) cin >> vec.at(i);
  
  for(int i = 0; i < num; i++){
    if(tmp == 0){
      tmp = abs(vec.at(i)-x);
      continue;
    }
    
    tmp = abs(gcd(tmp, vec.at(i)-x));
  }
  
  if(tmp == 0) cout << 1;
  else cout << tmp;
}
