#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, a, b = 0;
  cin >> N;
  vector<int> flag(101);
  
  for(int i = 0; i < N; i++){
    cin >> a;
    flag.at(a) = 1;
  }
  
  for(int i = 0; i < 101; i++){
    b += flag.at(i);
  }
  
  cout << b << endl;
}