#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  
  int A[N];
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  
  int count[N] = {};
  int test;
  for(int i = 0; i < N; i++){
    test = A[i] - 1;
    count[test]++;
  }
  sort(count, count + N);
  
  int integ;
  for(int i = 0; i < N - K; i++){
    integ += count[i];
  }
  
  cout << integ << endl;
}