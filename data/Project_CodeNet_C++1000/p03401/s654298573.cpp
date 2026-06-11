#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++){ 
    cin >> A[i];
  }
  int sum = 0;
  sum += abs(A[0]);
  for(int i = 0; i < N - 1; i++){
    sum += abs(A[i] - A[i + 1]);
  }
  sum += abs(A[N - 1]);
  int sum1 = sum;
  sum1 -= abs(A[0]);
  sum1 -= abs(A[1] - A[0]);
  sum1 += abs(A[1]);
  cout << sum1 << endl;
 
  for(int i = 1; i < N - 1; i++){
    sum1 = sum;
    sum1 -= abs(A[i] - A[i + 1]);
    sum1 -= abs(A[i] - A[i - 1]);
    sum1 += abs(A[i - 1] - A[i + 1]);
    cout << sum1 << endl;
  }
  sum1 = sum;
  sum1 -= abs(A[N - 1]);
  sum1 -= abs(A[N - 1] - A[N - 2]);
  sum1 += abs(A[N - 2]);

  cout << sum1 << endl;
  return 0;
}