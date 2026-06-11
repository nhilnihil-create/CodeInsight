#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long N, x; cin >> N >> x;
  long long A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  
  sort(A, A + N);
  long long count = 0;
  for (long long i = 0; i < N; i++){
    if (i == N - 1){
      if (A[i] == x) count++;
      break;
    }
    if (A[i] <= x){
      count++;
      x -= A[i];
    }
  }
  cout << count << endl;
}