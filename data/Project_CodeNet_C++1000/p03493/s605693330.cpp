#include <iostream>
using namespace std;
int main(void){
    // Your code here!
  int a;
  cin>>a;
  int b=a/100;
  int c=(a%100)/10;
  int d=(a%100)%10;
  if(b==1&&c==1&&d==1){
    cout<<3<<endl;
  }else if((b==0&&c==1&&d==1)||(b==1&&c==0&&d==1)||(b==1&&c==1&&d==0)){
    cout<<2<<endl;
  }else if((b==1&&c==0&&d==0)||(b==0&&c==1&&d==0)||(b==0&&c==0&&d==1)){
    cout<<1<<endl;
  }else{
    cout<<0<<endl;
  }
  
}
