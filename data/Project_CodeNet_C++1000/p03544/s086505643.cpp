#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int64_t> vec(100, 0);
  
  vec.at(0) = 2;
  vec.at(1) = 1;
  
  for(int i=2; i<n+1; i++){
    vec.at(i) = vec.at(i-1) + vec.at(i-2);
  }
  
  cout << vec.at(n) << endl;
}