#include <bits/stdc++.h>
using namespace std;
int main(){
  int A, N;
  cin >> N >> A;
  if(A > N){cout << "Yes" << endl;}
  else if(N%500 <= A){cout << "Yes" << endl;}
  else if(N%500 == 0){cout << "Yes" << endl;}
  else{cout << "No" << endl;}
}
