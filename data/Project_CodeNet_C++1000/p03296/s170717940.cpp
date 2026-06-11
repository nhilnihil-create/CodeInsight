#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int Ans=0;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  for(int i=1; i<N; i++){
    if(A.at(i)==A.at(i-1)){
      Ans++;
      A.at(i)=-1;
    }
  }
  cout << Ans << endl;
}