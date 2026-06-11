#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long A,B,C,K;
  cin >> A >> B >> C >> K;
  
  if(abs(A-B) > pow(10,18)){
    cout << "Unfair" << endl;
  }else if(K%2==0){
    cout << A - B << endl;
  }else{
    cout << B-A << endl;
  }
}