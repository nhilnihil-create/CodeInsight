#include <iostream>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  
  int sum;
  if(a+b<2*c){
    sum=a*x+b*y;
  }
  if(a+b>=2*c){
    int j=max(x,y);
    if(x<y){
      sum=min(2*j*c,2*x*c+b*(y-x));
    }else{
      sum=min(2*j*c,2*y*c+a*(x-y));
    }
  }
 
  cout<<sum<<endl;
}
  
    
