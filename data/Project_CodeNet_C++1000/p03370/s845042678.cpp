#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,X,sumg=0,sumk=0;
  cin >> N >> X;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>> A.at(i);
    sumg+=A.at(i);
    sumk++;
  }
  sort(A.begin(),A.end());
  while(true){
    if(sumg+A.at(0)<=X){
      sumg+=A.at(0);
      sumk++;
    }
    else{
      break;
    }
  }
  cout << sumk << endl;
}