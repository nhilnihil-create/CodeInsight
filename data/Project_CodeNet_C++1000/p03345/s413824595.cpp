#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  long long K;
  cin >> A >> B >> C >> K;
  if(abs(A-B)>1000000000000000000){
    cout << "Unfair" << endl;
  }
  else if(K%2==0){
    cout << A-B << endl;
  }
  else{
    cout << B-A << endl;
  }
}