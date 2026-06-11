#include <iostream>
#include <cmath>

using namespace std;
int main(){
  long long N, P, tmp, j;
  long long ret = 1;
  cin >> N >> P;
  
  if (N == 1) ret = P;
  else{
    long long max_p = ceil(pow(P, 1.0/(double)N));
    for (j=max_p; j >= 1; j--){
        tmp = pow(j, N);
        if (P % tmp == 0) break;
    }
    ret = j;
  }
  cout << ret << endl;
  return 0;
}
