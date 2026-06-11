#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int c=0;
  cin >> N;
  for (int i=0; i<N; i++){
    int A;
    int b=0;
    cin >> A;
    while (A%2==0){
     b++;
      A=A/2;
    }
    if (i==0) {
      c=b;
    }
    if (b<c){
     c=b;
    }
    else
      c=c;
    
  }
  cout << c << endl;
    
    
}
   