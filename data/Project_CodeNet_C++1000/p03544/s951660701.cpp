#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
  vector <long long  int> lucas(100,0);
  long long  int a[100],tmp;
  a[0] = 2,a[1]=1;
  lucas.at(0) = 2;
  lucas.at(1) = 1;
  for(int i = 2;i<100;i++){
    a[i] = a[i-1] + a[i-2];
    lucas.at(i) = a[i];
  }
  int c;
  cin >> c;
  cout << lucas.at(c);
}