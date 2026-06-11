#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int A[4];
  A[3]=N%10;
  N/=10;
  A[2]=N%10;
  N/=10;
  A[1]=N%10;
  N/=10;
  A[0]=N%10;
  
  char op[3];
  
  for(int tmp=0;tmp<(1<<3);tmp++){
    bitset<3> s(tmp);
    
    int sum=A[0];
    
    for(int i=0;i<3;i++) {
      if(s.test(i)){
        sum+=A[i+1];
        op[i]='+';
      }
      else{
        sum-=A[i+1];
        op[i]='-';
      }
    }
    if(sum==7){
      break;
      
    }
  }
  cout<<A[0]<<op[0]<<A[1]<<op[1]<<A[2]<<op[2]<<A[3]<<"=7"<<endl;
  
}
