#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int N;
  cin >> N;
  
  vector<int>h(N);
  int sum = 0;
  for (int i = 0; i < N; i++){
    cin >> h.at(i);
    sum += h.at(i);
    if (i != 0){
      sum -= min(h.at(i),h.at(i-1));
    }
  }
  cout << sum << endl;
}
  