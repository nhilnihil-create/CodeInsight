#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long> A(N);
  vector<long long> sum(N);
  for (long long i = 0; i < N; i++) {
    cin >> A[i];
    if (i == 0) {
      sum[0] = A[0];
    } else {
      sum[i] = sum[i-1]+A[i];
    }
  }
  //cout << sum[N-1] << endl;

  vector<long long> F(N);
  long long ix = 0;
  long long ix2 = 2;
  long long mm = 1000000000000;
  for (long long i = 1; i < N-2; i++) {
    for (long long j = ix; j < i; j++) {
      if (abs(sum[j]-(sum[i]-sum[j])) < abs(sum[j+1]-(sum[i]-sum[j+1]))) {
        ix = j;
        break;
      }
    }
    for (long long j = ix2; j < N-1; j++) {
      if (abs(sum[N-1]-sum[j]-(sum[j]-sum[i])) < abs(sum[N-1]-sum[j+1]-(sum[j+1]-sum[i]))) {
        ix2 = j;
        break;
      }
    }
    auto lst = {sum[ix], sum[i]-sum[ix], sum[N-1]-sum[ix2], sum[ix2]-sum[i]};
    long long check = sum[ix] + (sum[i]-sum[ix]) + sum[N-1]-sum[ix2] + sum[ix2]-sum[i];
    //cout << check << endl;
    long long res = max(lst)-min(lst);
    //cout << max(lst)-min(lst) << endl;
    mm = mm > res ? res : mm;
  }
  cout << mm << endl;
  return 0;
}