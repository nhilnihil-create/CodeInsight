#include<bits/stdc++.h>

using namespace std;

int64_t ryuka(int N) {
  vector<int64_t> ryuka_array(N+1);
  ryuka_array.at(0) = 2;
  ryuka_array.at(1) = 1;
  for(int i=2; i<=N; i++) {
    ryuka_array.at(i) = ryuka_array.at(i - 1) + ryuka_array.at(i - 2);
  }
  return ryuka_array.at(N);
}

int main(void) {
  int N;
  cin >> N;
  
  cout << ryuka(N) << endl;
}