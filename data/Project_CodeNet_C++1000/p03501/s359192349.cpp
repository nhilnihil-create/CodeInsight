#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B, a, b;
  cin >> N >> A >> B;
  a = A * N;
  b = B;
  if(a < b){
    cout << a << endl;
  }
  if(a > b){
    cout << b << endl;
  }
  if(a == b){
    cout << a << endl;
  }
}
