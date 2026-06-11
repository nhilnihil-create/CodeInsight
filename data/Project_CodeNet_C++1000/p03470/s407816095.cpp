#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, max, j = 0, sum = 0;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++)
    cin >> vec.at(i);
  while (true){
    max = 0;
    for (int i = 0; i < N; i++){
      if (max < vec.at(i)){
        max = vec.at(i);
        j = i;
      }
      else if (max == vec.at(i))
        vec.at(i) = 0;
    }
    if (max == 0)
      break;
    sum++;
    vec.at(j) = 0;
  }
  cout << sum << endl;
}
      
  