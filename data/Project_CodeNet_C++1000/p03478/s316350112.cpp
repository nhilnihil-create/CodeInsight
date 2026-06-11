#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >> N >> A >> B;
  int M = 1;

  vector<int> sum(N+1,0);
  for (int i = 1; i < N+1; i++) {
    M = i;
    while (M != 0){
      sum.at(i) += M % 10; 
      M = (M - M % 10)/10;
    }
  }
  
  long long Sum = 0;
  for (int i = 1; i < N+1; i++) {
    if (sum.at(i) >= A && sum.at(i) <= B){
      Sum += i;
    }
  }
  cout << Sum << endl;
}
  