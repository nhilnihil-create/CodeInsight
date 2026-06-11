#include<iostream>
using namespace std;
int main(){
  string a;
  cin>>a;
  int k=0,h=0,g=0;
  for(int i=0;i<3;i++){
    if(a.at(i)=='a')
      k++;
    else if(a.at(i)=='b')
      h++;
    else if(a.at(i)=='c')
      g++;
  }
  if(k==1&&h==1&&g==1)
    cout<<"Yes";
  else
    cout<<"No";
    return 0;
}
