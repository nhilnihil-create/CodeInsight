#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int64_t a,b,c;
  cin >> N;
  a=2;
  b=1;
  for(int i=0;i<(N-1);i++){
    c=a+b;
    a=b;
    b=c;
  }
  cout << b << endl;
}
