#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> A(5);
  for(int i=0;i<5;i++){
    cin >> A.at(i);
  }
  vector<int> B(5);
  int sum=0;
  for(int i=0;i<5;i++){
    if(A.at(i)%10==0){
      B.at(i)=A.at(i);
    }
    else{
      B.at(i)=A.at(i)-A.at(i)%10+10;
    }
    sum+=B.at(i);
  }
  int minB=10000000;
  for(int i=0;i<5;i++){
    minB=min(minB,sum-B.at(i)+A.at(i));
  }
  cout << minB << endl;
}