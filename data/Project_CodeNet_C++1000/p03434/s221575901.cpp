#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  int sum = 0;
  
  for (int i=0;i < N;i++) {
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  
  int count1=0;
  for (int i=0;i<N;i=i+2) {
    sort (vec.begin(),vec.end());
    reverse (vec.begin(),vec.end());
    count1 += vec.at(i);
  }
  
  cout << count1-(sum-count1) << endl;
}