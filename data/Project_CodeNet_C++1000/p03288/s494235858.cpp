#include<iostream>

using namespace std;

int main(void)
{
  int r; cin>>r;
  
  if(r<2800){
    if(r<1200){
      puts("ABC");
    }else{
      puts("ARC");
    }
  }else{
    puts("AGC");
  }
  
  return 0;
}