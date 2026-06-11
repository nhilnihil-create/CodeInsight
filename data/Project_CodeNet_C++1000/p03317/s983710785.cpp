#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i=0; i<N; i++){
      cin >> A.at(i);
  }
  int count = 0;
  while(1){
      N -= K-1;
      count += 1;
      if(N <= 1){
          break;
      }
  }
  cout << count << endl;
}
