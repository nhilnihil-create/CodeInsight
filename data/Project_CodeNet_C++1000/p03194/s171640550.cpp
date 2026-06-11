#include <iostream>
#include <map>
using namespace std;

int main(){
  long N, P, p, ans;
  map<long, long> m;  
  
  cin >> N >> P;
  p = P;
  
  while (p % 2 == 0) {
    ++(m[2]);
    p /= 2;
  }
  long i;
  for (i = 3; i * i <= P; i += 2) {
    while (p % i == 0) {
      ++(m[i]);
      p /= i;
    }
  }
  if (p > 1) ++(m[p]);

  ans = 1;
  for (const auto s : m){
cerr << s.first << " " << s.second << endl;
    for(i = 0; i < s.second / N; ++i){
      ans *= s.first;
    }
  }
  cout << ans << endl;
  return 0;
}