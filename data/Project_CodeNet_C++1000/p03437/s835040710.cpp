#include <bits/stdc++.h>
using namespace std;

int main(){
  long long X,Y;
  X=0;
  Y=0;
  cin>>X>>Y;
  if(X%Y==0){
    cout<<-1<<endl;
    return 0;
  }
  
  while(X<=10'0000000000'00000000){
    if(X%Y!=0){
      cout<<X<<endl;
      return 0;
    }
    X=X+X;
  }
  cout<<-1<<endl;
  return 0;
}
