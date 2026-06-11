#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  
  vector<tuple<string,int,int>> vec;
  
  string st;
  int n;
  for (int i = 0; i < N; i++) {
    cin >> st >> n;    
    vec.push_back(make_tuple(st, n, i+1));
  }
  
  sort(vec.begin(), vec.end());
  
  tuple<string,int,int> m;
  for (int i = 0; i < N-1; i++) {
    for (int j = 0; j < N-1; j++) {
      if (get<0>(vec.at(j)) == get<0>(vec.at(j+1)) &&
          get<1>(vec.at(j)) < get<1>(vec.at(j+1))) {
        m = vec.at(j);
        vec.at(j) = vec.at(j+1);
        vec.at(j+1) = m;
      }
    }
  }
  
  for (int i = 0; i < N; i++) {
    cout << get<2>(vec.at(i)) << endl;
  }
  
  return 0;
}
