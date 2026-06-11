#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,K;
  cin >> A >> B >> K;
  vector<int> C;
  for(int i=A;i<B+1;i++){
    if(i<A+K){
      C.push_back(i);
    }
    else if(B-K<i){
      C.push_back(i);
    }
  }
  int D=C.size();
  for(int i=0;i<D;i++){
    cout << C.at(i) << endl;
  }
}
