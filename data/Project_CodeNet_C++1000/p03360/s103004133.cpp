#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  int num;
  long long kekka = 0;
  
  vector<int> vec(3);
  
  cin >> a >> b >> c >> num;
  vec.at(0) = a;
  vec.at(1) = b;
  vec.at(2) = c;
  
  sort(vec.begin(), vec.end());
  
  kekka = vec.at(2);
  for(int i = 0; i < num; i++){
    kekka *=  2;
  }
  cout << vec.at(0) + vec.at(1) + kekka;
}
