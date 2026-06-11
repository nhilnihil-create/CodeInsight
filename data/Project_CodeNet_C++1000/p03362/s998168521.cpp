#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<bool> prime(55556, true);
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i <= 55555; i++){
    if (prime[i]){
      for (int j = i * 2; j <= 55555; j += i){
        prime[j] = false;
      }
    }
  }
  int N;
  cin >> N;
  vector<int> A;
  for (int i = 1; i <= 55555; i += 5){
    if (prime[i]){
      A.push_back(i);
      if (A.size() == N){
        break;
      }
    }
  }
  for (int i = 0; i < N; i++){
    cout << A[i];
    if (i < N - 1){
      cout << ' ';
    }
  }
  cout << endl;
}