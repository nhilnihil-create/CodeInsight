#include<bits/stdc++.h>
using namespace std;

int main(){
  int r, d;
  vector<int> x(20);
  cin >> r >> d >> x[0];
  for(int i = 1; i <= 10; i++) x[i] = r * x[i-1] - d;
  for(int i = 1; i <= 10; i++) cout << x[i] << endl;
  return 0;
}