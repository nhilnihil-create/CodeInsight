#include<bits/stdc++.h>
using namespace std;

string seven(vector<int> A){
  string s="";
  for(int bit=0;bit<(1<<3);++bit){
    bitset<3> tmp(bit);
    int sum=A.at(0);
    s=to_string(A.at(0));
    for(int i=0;i<3;++i){
      if(tmp.test(i)){
        sum+=A.at(i+1);
        s+="+";
      }
      else{
        sum-=A.at(i+1);
        s+="-";
      }
      s+=to_string(A.at(i+1));
    }

    if(sum==7){
      s+="=7";
      break;
    }
  }
  return s;
}

int main(){
  int N;
  cin >> N;
  vector<int> A(4);
  for(int i=3;i>=0;i--){
    A.at(i)=N%10;
    N/=10;
  }

  cout << seven(A) << endl;
  
}
