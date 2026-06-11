#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  vector<long> list;
  
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    long in;
    
    cin >> in;
    
    list.push_back(in - (i + 1));
  }
  
  sort(list.begin(), list.end());
  
  int median_of_list = N % 2 == 0 ? (list.at(N / 2) + list.at(N / 2 - 1)) / 2 : list.at(N / 2); 
  long minimum_sum = 0;
  
  for (int i = 0; i < N; i++) {
    minimum_sum += abs(list.at(i) - median_of_list);
  }
  
  cout << minimum_sum << endl;
  
  return 0;
}