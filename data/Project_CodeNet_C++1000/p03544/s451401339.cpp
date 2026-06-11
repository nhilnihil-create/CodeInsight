#include <bits/stdc++.h>
using namespace std;

vector<int64_t>  l(87, -1);

int64_t lucas(int i){
  
  if(i == 0){
    l.at(0) = 2;
    return l.at(0);
  }
  if(i == 1){
    l.at(1) = 1;
    return l.at(1);
  }
  if(l.at(i) != -1){
    return l.at(i);
  }
  
  l.at(i) = lucas(i - 1) + lucas(i - 2);
  return l.at(i);
}
 
int main() {
  int n;
  cin >> n;
  cout << lucas(n) << endl;
}