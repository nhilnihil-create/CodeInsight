#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  int ans =0;
  if(A+B>=C){
    cout << B+C << endl;
    return 0;
  }
  cout << A+2*B+1 << endl;
  return 0;
}