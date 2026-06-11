#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin>>N>>A>>B;
  int plan1;
  plan1= A*N;
  if (plan1 >= B) {
    cout << B;
  }
  else {
    cout << plan1;
  }
}