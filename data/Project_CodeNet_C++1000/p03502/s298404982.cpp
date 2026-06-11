#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a[10]={0,0,0,0,0,0,0,0,0,0};
  cin >> N;
  int i=0, sum=0;
  int A=N;
  
  while(N>0){
    a[i] = N % 10;
    N /= 10;
    sum += a[i];
    
    i++;
  }
  
  if(A % sum == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}
