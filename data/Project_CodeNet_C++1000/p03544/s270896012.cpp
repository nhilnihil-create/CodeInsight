#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int64_t> k(N+1);
  k.at(0) = 2;
  k.at(1) = 1;
 
 for(int i = 2; i <= N; i++) {
   k.at(i) = k.at(i-1) + k.at(i-2);
 }
  cout << k.at(N) << endl;
}