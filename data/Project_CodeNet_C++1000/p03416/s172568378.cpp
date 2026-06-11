#include <bits/stdc++.h>
using namespace std;


int main(){
  int A,B;
  cin>>A>>B;
  int sum =0;
  for(int i =0;i<B-A+1;i++){
    string a = to_string(A + i);
    if(a.at(0)==a.at(4)&&a.at(1)==a.at(3)){
      sum++;
    }
  }
  cout<<sum<<endl;
}