#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A;
  int count;
  int ans = 10000;
  for(int i=0; i<N; i++){
    cin >> A;
    count = 0;
    while(A%2 == 0){
      A /= 2;
      count++;
    }
    if(count < ans){
      ans = count;
    }
  }
  cout << ans << endl;
}