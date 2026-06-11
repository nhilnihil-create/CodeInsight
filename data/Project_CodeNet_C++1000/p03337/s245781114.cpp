#include "iostream"
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  int c=(a+b);
  int d=(a-b);
  int e=(a*b);
  
  cout<<max(max(c,d),e)<<endl;



}
