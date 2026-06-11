#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<string> W(N);
  for (int i = 0; i < N ; i++) {
    cin >> W.at(i);
  }
  
  int count = 0;
  
  for (int i = 0; i < N - 1 ; i++) {
    if (W.at(i + 1).at(0) != W.at(i).at(W.at(i).size() - 1)){
      count++;
      break;
    }
    for (int j = i + 1; j < N ; j++) {
      if (W.at(i) == W.at(j)){
        count++;
        break;
      }
    }
  }
  
  if (count > 0){
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}