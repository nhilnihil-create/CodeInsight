#include<iostream>
#include <string>
using namespace std;

int main(){
  string N;
  int n=0,m=0;
  cin >> N;
  
  if(N[0]==N[1]){
    n++;
    if(N[2]==N[1])
      n++;
  }
  if(N[2]==N[1]){
    m++;
    if(N[2]==N[3])
      m++;
  }
  if(n==2||m==2)
    cout << "Yes";
  else
    cout << "No";
}