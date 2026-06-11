#include<iostream>
#include<algorithm>
using namespace std;

int A[50];

int main() {
  int N; cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A, A+N);
  int sum = 0;
  for (int i = 0; i < N-1; i++) sum += A[i];
  cout << ( A[N-1] < sum ? "Yes" : "No" ) << endl;
}