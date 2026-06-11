#include <bits/stdc++.h>
using namespace std;

int main(){

  int N;
  cin >> N;
  
  int x = N / 1000;
  int y = N / 100 - 10 * x;
  int z = N / 10 - 100 * x - 10 * y;
  int w = N - 1000 * x - 100 * y -10 * z;
  
  if (x == y && y == z || y == z && z == w){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  
}