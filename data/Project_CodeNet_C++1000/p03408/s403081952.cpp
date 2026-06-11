#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,A,X;
  cin >> N;
  vector<string> B(N);
  for (int i=0;i<N;i++){
    cin >> B.at(i);
  }
  cin >> M;
  vector<string> R(M);
  for (int i=0;i<M;i++){
    cin >> R.at(i);
  }

  X=0;
  for (int i=0;i<N;i++){
    A=1;
    for (int j=i+1;j<N;j++){
      if(B.at(i)==B.at(j)){
        A++;
      }
    }
    for (int j=0;j<M;j++){
      if(B.at(i)==R.at(j)){
        A--;
      }
    }
    if(A>X){
      X=A;
    }
  }
  cout << X << endl;
}