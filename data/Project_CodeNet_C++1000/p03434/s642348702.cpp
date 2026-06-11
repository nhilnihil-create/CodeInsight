#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int o = 0;  // bobutoarisukimeru
  int l = 0; // -1
  int MAX = 0;
  int a = 0;
  int b = 0;
  vector<int> vec(N);
  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
  }
  for (int p = 0; p < N; p++){
    MAX = 0;
    for (int i = 0; i < N; i++){
      if (MAX <= vec.at(i)){
        MAX = vec.at(i);
        l = i;
      }
    }
    vec.at(l) = -1;
    if (o % 2  == 0){
      a += MAX;
      o++;
    }else{
      b += MAX;
      o++;
    }
  }
  cout << a- b << endl;
}