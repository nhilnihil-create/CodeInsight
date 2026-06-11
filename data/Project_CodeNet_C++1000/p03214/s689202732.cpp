#include<bits/stdc++.h>
using namespace std;

int main(){
  int iN;
  cin >> iN;
  vector<double> A(iN);
  double Sum=0;
  for(int i=0; i<iN; i++){
    cin >> A.at(i);
    Sum+=A.at(i);
  }
  double N=(double)iN;
  double K=Sum/N;
  double Ans=N+1;
  double now=100000000;
  for(int i=N-1; i>=0; i--){
    if(abs(A.at(i)-K)<=now){
      Ans=i;
      now=abs(A.at(i)-K);
    }
  }
  cout << (int)Ans << endl;
}