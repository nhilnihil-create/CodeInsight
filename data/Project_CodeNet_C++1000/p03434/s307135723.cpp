#include<bits/stdc++.h>
using namespace  std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  
  int sum_a=0, sum_b=0;
  for(int i=0; i < vec.size(); i++){
    if(i%2 == 0)sum_a += vec.at(i);
    else sum_b += vec.at(i);
  }
  cout << sum_a - sum_b << endl;
  
}