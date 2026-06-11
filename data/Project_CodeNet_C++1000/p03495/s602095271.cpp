#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
 
  int A[N] = {0};

  for (int i = 0; i < N; i++) {
    int ai;
    cin >> ai;
    A[ai]++;
  }

  sort(A, A+N, greater<int>());

  int sum=0;
  for (int i = 0; i < K; i++) sum += A[i];
  cout << N - sum << endl;
}
