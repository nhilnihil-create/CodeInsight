#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> num(N);
  
  for(int i = 0; i < N; i++) {
    cin >> num.at(i);
  }
  sort(num.begin(), num.end());
  cout << num.at(num.size() - 1) - num.at(0);
}