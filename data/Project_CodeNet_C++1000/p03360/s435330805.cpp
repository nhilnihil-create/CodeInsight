#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,K;
  cin>>A>>B>>C>>K;
  cout<<A+B+C-max(A,max(B,C))+max(A,max(B,C))*((int)pow(2,K))<<endl;
}