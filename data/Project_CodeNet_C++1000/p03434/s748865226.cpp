#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, a;
  cin >> n;
  
  vector<int> vec(n);
  for(int k = 0; k < n; k++){
    cin >> a;
    vec.at(k) = a;
  }
  
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  
  int alicePoint = 0;
  for(int i = 0; i < vec.size(); i += 2){
    alicePoint += vec.at(i);
  }
  int bobPoint = 0;
  for(int i = 1; i < vec.size(); i += 2){
    bobPoint += vec.at(i);
  }
  
  cout << alicePoint -  bobPoint << endl;
}