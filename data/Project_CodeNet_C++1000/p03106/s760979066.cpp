#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, k; cin >> a >> b >> k;
  vector<int> vec;
  for(int i=1;i<=max(a,b);i++){
    if(a % i == 0 && b % i == 0) vec.push_back(i);
  }
  reverse(vec.begin(), vec.end());
  cout << vec[k-1] << endl;
  return 0;
}