#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  long long int N, A, B, C, D, E;
  cin >> N >> A >> B >> C >> D >> E;
  
  long long int ans, min_c = min({A, B, C, D, E});
  ans = N / min_c + 5;
  if(N % min_c == 0) ans--; 
  
  cout << ans << endl;
  
  return 0;
}