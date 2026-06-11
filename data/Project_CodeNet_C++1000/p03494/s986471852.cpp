#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A;
  cin >> N;
  int count = 100;
  int x;
 
  for (int i = 0; i < N; i++){
    x = 0;
    cin >> A;
    while (A % 2 == 0 && A > 0){
      A /= 2;
      x++;
    }
    count = min(count,x);
  }
  cout << count << endl;
}