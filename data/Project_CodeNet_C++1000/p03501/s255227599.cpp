#include<bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >> N >> A >> B;
  
  int one = A*N, two = B;
  
  if(one <= two)
    cout << one << endl;
  else
    cout << two << endl;
}