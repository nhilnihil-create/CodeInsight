#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t a = 2;
  int64_t b = 1;
  int64_t c;
  int N;
  
  cin >> N;
  
  if(N==0)
    cout << 0 << endl;
  if(N==1)
    cout << 1 << endl;
  if(N > 1){
  for(int i=2; i<N+1; i++){
    c=a+b;
    a=b;
    b=c;
  }
  cout << c << endl;
}
}