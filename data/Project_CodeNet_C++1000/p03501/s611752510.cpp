#include <bits/stdc++.h>
using namespace std;

int main() {
 int N;
 int A;
 int B; 

   
  cin >> N >> A >> B;
  if ((N*A)>=B) {cout << B << endl;}
  else if ((N*A)<=B) {cout << N*A << endl;}
}
