#include <bits/stdc++.h>
using namespace std;



int main(){
  int N, a, b, c; cin >> N;

  a = N / 100;
  b = (N % 100) / 10;
  c = (N % 10);
  
  cout << (10-a) * 100 + (10-b) * 10 + (10-c) << endl;

}
