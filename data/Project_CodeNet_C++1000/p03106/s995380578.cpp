#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,K;
  cin >> A >> B >> K;
  int i=0;
  int j=A+1;
  while(i!=K){
    j--;
    if(A%j==0&&B%j==0){
      i++;
    }
  }
  cout << j << endl;
}
