#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> h(N);
  for (int i=0; i < N; i++){
    cin >> h.at(i);
  }
  sort(h.begin(), h.end());
  int a = 0, b = 0;
  for (int j = 0; j < N; j++){
    if (j % 2 == 0){
      a += h.at(N-j-1);
    }else{
      b += h.at(N-j-1);
    }
  }
  int ans = a - b;
  cout << ans << endl;
}