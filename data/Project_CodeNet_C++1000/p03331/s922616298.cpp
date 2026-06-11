#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int A, B;
  int Ans=100000000;
  int subans=0;
  string S, T;
  int L, M;
  for(int i=1; i<=N/2; i++){
    subans=0;
    A=i;
    B=N-i;
    S=to_string(A);
    T=to_string(B);
    L=S.size();
    M=T.size();
    for(int i=0; i<L; i++){
      subans+=S.at(i)-'0';
    }
    for(int i=0; i<M; i++){
      subans+=T.at(i)-'0';
    }
    Ans=min(Ans, subans);
  }
  cout << Ans << endl;
}