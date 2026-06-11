#include<iostream>
using namespace std;
int main(){
  int a1,a2,a3,m,n;
  cin>>a1>>a2>>a3;
  m=max(max(a1,a2),a3);
  n=min(min(a1,a2),a3);
  cout<<m-n<<endl;
}