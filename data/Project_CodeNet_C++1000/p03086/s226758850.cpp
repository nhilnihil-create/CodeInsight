#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  int start=-1,t=0,i;
  string S;
  cin >> S;
  for(i=0;i<S.length();i++){
    if(S.at(i)=='A' || S.at(i)=='T' || S.at(i)=='C' || S.at(i)=='G'){
      if(start==-1)start=i;
    }else{
      if((start !=-1)&&i-start>t)t=i-start;
      start=-1;
    }
  }
  if((start !=-1)&&i-start>t)t=i-start;
  cout << t << endl;
}