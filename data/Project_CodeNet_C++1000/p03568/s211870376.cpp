#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  int Ans=(int)pow(3, N);
  int pro=1;
  for(int i=0; i<N; i++){
    if(A.at(i)%2==0){
      pro*=2;
    }
  }
  Ans-=pro;
  cout << Ans << endl;
}