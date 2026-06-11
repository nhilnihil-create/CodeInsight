#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int MAX = 0;
  int k = 0;
  vector<int> vec(N);
  int kaburi = 0;
  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
  }
  for (int p = 0; p < N; p++){
    MAX = 0;
    for (int i = 0; i < N; i++){
      if (MAX <= vec.at(i)){
        MAX = vec.at(i);
        k = i;
      }
    }
    vec.at(k) = -1;
    for (int i = 0; i < N; i++){
      if (MAX == vec.at(i)){
        MAX = vec.at(i);
        vec.at(i) = -1;
        kaburi++;
      }
    }    
  }
  cout << N - kaburi << endl;
}