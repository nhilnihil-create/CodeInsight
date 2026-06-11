#include "iostream"
using namespace std;
int main(){
  int a;int p;
  cin>>a>>p;
  int k=(((a*3)+p)-(((a*3)+p)%2))/2;
  cout<<k<<endl;
}
