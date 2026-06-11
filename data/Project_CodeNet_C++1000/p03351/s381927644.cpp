#include "iostream"
using namespace std;
int abs(int a){
  if(a<=0){
    return(-1*a);
  }
  else{
    return (a);
  }
}
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if((abs(a-c))<=d){
    cout<<"Yes"<<endl;
  }
  else if(((abs(a-b))<=d)&&((abs(b-c))<=d)){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
