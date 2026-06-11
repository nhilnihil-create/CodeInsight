#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,max = 0, sum = 0;
  cin >> N;
  vector<int> vec1(N);
  for (int i = 0; i < N; i++) {
  cin >> vec1.at(i);
  if (max < vec1.at(i)){
  max = vec1.at(i);
  }
  }
  for (int i = 0; i < max; i++){
   vector<int> vec2(N + 2);
   for (int n = 0; n < N; n++){
   if (vec1.at(n) > i ) {
   vec2.at(n + 1) = 1;
   }
   }
   int count = 0;
   for (int j = 0; j < N + 1 ;j++ ) {
   if (vec2.at(j) != vec2.at(j + 1)){
   count++;
   }
   }
   count = count / 2;
   sum += count;
   }
  cout << sum << endl;
}
  

