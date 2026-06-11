#include <iostream>
using namespace std;
int main(){
  int N,n;
  int sum = 0;
  cin >> N;
  n = N;
  while(n>10){                                                                          sum += n%10;
    n = n/10;
  }
  sum += n;
  if(N%sum == 0) cout << "Yes" << "\n";
  else  cout << "No" << "\n";
  return 0;
}