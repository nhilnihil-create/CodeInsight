#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,C;
  cin >> N >> A >> B;
  C=abs(A-B);
  if(C%2==0){
    cout << "Alice" << endl;
  }
  else{
    cout << "Borys" << endl;
  }
}
    
  