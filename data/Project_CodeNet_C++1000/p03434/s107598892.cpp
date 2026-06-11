#include<bits/stdc++.h>
using namespace std;
int main() {
  int Alice = 0, Bob = 0, N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) Alice += vec[i];
    else Bob += vec[i];
  }
  cout << abs(Alice - Bob) << endl;
}