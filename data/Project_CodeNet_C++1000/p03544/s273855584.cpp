#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  unsigned long long a=2,b=1;
  for (int i=0;i<max(0,N-1);i++){
    unsigned long long c=b;
    b+=a;
    a=c;
  }
  if (N==1){
    cout << 1 << endl;
  }
  else{
  	cout << b << endl;  
  }
}