#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){

  int X;
  cin>>X;
  vector<int>data(X,0);
  long long int num=0;
  for(int i=1;i<=X;i++){    
    for(int j=2;j<=6;j++){
    
      num=pow(i,j);
      //cout<<num<<endl;
      if(num<=X){
      
        data[num-1]=1;
      }
    }
  }
  for(int i=X;i>0;i--){
  
    if(data[i-1]==1){
    
      cout<<i;
      return 0;
    }
  }
}