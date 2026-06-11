#include<iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(a+b-1<c)
    cout<<"NO";
  else if(a>c)
    cout<<"NO";
  else 
    cout<<"YES";
  return 0;
}
