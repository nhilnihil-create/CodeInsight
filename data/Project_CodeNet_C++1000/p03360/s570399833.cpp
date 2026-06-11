#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  int M=max(A, max(B, C));
  cout << M*pow(2, K)-M+A+B+C << endl;
}