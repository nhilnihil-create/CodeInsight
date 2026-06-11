#include<iostream>
using namespace std;
int main(){
  string a;
  cin>>a;
  int k=0;
  for(int i=0;i<a.size();i++){
    if(a.at(i)=='+')
      k++;
    else
      k--;
  }
  cout<<k;
  return 0;
}
