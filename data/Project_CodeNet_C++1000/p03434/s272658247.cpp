#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, max, k = 0, l = 1, sum = 0;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++)
    cin >> vec.at(i);
  for (int i = 0; i < N; i++){
    max = 0;
    for (int j = 0; j < N; j++){
      if (max < vec.at(j)){
        max = vec.at(j);
        k = j;
      }
    }
    sum += max * l;
    l *= -1;
    vec.at(k) = 0;
  }
  cout << sum << endl;
}
      
  