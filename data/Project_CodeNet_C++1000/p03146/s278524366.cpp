#include<iostream>
#include<vector>
using namespace std;

int main(){
  int s;
  vector<int> tmp(10000);
  cin >> s;
  tmp.at(0)=s;
  for(int i=1;i<10000;i++){
    if(tmp.at(i-1)%2==0){
      tmp.at(i)=tmp.at(i-1)/2;
    }else{
      tmp.at(i)=3*tmp.at(i-1)+1;
    }
    for(int j=0;j<i;j++){
      if(tmp.at(i)==tmp.at(j)){
        cout << i+1 << endl;
        return 0;
      }
    }
  }
  return 0;
}