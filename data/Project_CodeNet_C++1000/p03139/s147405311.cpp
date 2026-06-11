#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  if(A+B<=N){
    if(A>=B){
      cout << B << " 0" << endl;
      return 0;
    }
    cout << A << " 0" << endl;
    return 0;
  }
  if(A>=B){
    cout << B << ' ' << A+B-N << endl;
    return 0;
  }
  cout << A << ' ' << A+B-N << endl;
  return 0;
}