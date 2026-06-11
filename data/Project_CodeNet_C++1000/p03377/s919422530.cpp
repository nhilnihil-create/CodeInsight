#include "iostream"
using namespace std;
int main(){
  int a,b,x;
  cin>>a>>b>>x;
  if((x<a)||(x>(a+b))||((x==(a+b))&&(x!=a))){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
  }
}
