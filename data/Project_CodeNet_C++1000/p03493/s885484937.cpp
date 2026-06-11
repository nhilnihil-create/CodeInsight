#include<iostream>
#include<string.h>

using namespace std;

int main(){
  int a;
  int count=0;
  cin >> a;
  
  if(a==1 || a==10 || a==100){
    count=1;
  }else if(a==11 || a==101 || a==110){
    count=2;
  }else if(a==111){
    count=3;
  }else{
    count=0;
  }
  cout << count << endl;
}