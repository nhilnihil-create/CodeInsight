#include <iostream>
using namespace std;

int main() {
  int a,b;
  cin>>a>>b;
  if(a>b) return 0;
  int k=b-a,t=0;
  while(k>0){
    t+=k;
    k--;
  }
  
  cout<<t-b<<endl;
}