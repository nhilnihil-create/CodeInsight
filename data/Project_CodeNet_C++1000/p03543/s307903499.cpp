#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a;
    cin>>a;
    int b=a/1000;
    int c=(a%1000)/100;
    int d=(a%100)/10;
    int e=a%10;
  	if((b==c&&c==d)||(c==d&&d==e)||(b==c&&c==d&&d==e)){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  
}
