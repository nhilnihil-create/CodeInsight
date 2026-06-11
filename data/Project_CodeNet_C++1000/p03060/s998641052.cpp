#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,sum=0; cin >> N;
  vector<vector<int>> data(2,vector<int>(N));

  for(int i=0; i<2; i++) {
    for(int j=0; j<N; j++) {
      cin >> data.at(i).at(j);
    }
  }
  for(int i=0; i<N; i++) {
  if(data.at(0).at(i)>data.at(1).at(i)) {
      sum += data.at(0).at(i)-data.at(1).at(i);
  }
  }
  cout << sum << endl;
}