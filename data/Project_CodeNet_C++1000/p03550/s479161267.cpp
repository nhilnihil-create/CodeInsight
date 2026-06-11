#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
 
int main() {
  int N, Z, W; cin >> N >> Z >> W;
  int A[N]; for (int i=0; i<N; i++) cin >> A[i];

  int result;
  if ( N != 1 ) result = max( abs(A[N-1]-W), abs(A[N-1]-A[N-2]) );
  else result = abs(A[N-1]-W);
  cout << result << endl;
  return 0;
}