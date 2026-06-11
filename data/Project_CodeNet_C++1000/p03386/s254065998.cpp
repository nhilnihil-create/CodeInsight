#include<iostream>

int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  for(int i=a;i<a+c&&i<=b;i++){
    std::cout<<i<<std::endl;
  }
  if(a+c-1>=b){
  }else if(a+c-1>=b-c+1){
    for(int i=a+c;i<=b;i++){
      std::cout<<i<<std::endl;
    }
  }else if(b-c+1>a+c-1){
    for(int i=b-c+1;i<=b;i++){
      std::cout<<i<<std::endl;
    }
  }
   return 0;
}

