#include "iostream"
using namespace std;
int main(){
  int a; int b;int t;
  cin>>a>>b>>t;
  int k=b;
  int w=a;
  if(a>t){
    cout<<0<<endl;

  }
  else if(a==t){
    cout<<a*b<<endl;
  }
  else{
    while(a<=t){
      a+=w;
      b+=k;
    }
    cout<<b-k<<endl;
  }
}
