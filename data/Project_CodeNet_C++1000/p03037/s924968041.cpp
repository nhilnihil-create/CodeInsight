#include <iostream>
using namespace std;

int main() {
  int N, M, a[100001] = {}, sum[100001] = {}, l, r, count = 0;
  cin >> N >> M;
  for (int i = 0; i < M; i++){
    cin >> l >> r;
    a[l] += 1;
    a[r+1] += -1;
  }
  for (int j = 1; j <= N+1; j++){
    sum[j] = sum[j-1] + a[j];
    if (sum[j] == M) count++; 
  }
  cout << count << endl;
  return 0;
}