#include <bits/stdc++.h>
using namespace std;
int main(){
  int x, N, sum;
  cin >> N;
  sum = 0;
  x = N;
  while(x != 0){
    sum += x % 10;
    x = (x - x % 10) / 10;
  }
  
  if (N % sum ==0) cout << "Yes" << endl;
  else cout << "No" << endl;

}