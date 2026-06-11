#include "iostream"
using namespace std;
int main(){
  int h;int w;int h1; int w1;
  cin>>h>>w;
  cin>>h1>>w1;
  if(h1==h||w1==w){
    cout<<0<<endl;

  }
  else{
    cout<<(w-w1)*(h-h1)<<endl;
  }
}
