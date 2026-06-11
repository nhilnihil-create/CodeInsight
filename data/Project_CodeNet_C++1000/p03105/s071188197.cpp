#include "iostream"
using namespace std;
int main(){
  int a;int b;int c;
  cin>>a>>b>>c;
  if(b>a){
    int d=0;
    while((b>=a)&&(c!=0)){
      c-=1;
      b-=a;
      d+=1;
    }
    cout<<d<<endl;
  }
  else if(a>b){
    cout<<0<<endl;
  }
  else{
    cout<<1<<endl;
  }

}
