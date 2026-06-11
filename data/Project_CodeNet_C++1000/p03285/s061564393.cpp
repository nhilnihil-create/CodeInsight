#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int count;
  for (int i = 0; i < 30; i++){
    for (int j = 0; j < 30; j++){
      if (4 * i + 7 * j == N){
        count++;
      }
    }
  }
  if(count) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}