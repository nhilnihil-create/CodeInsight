#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B;
  cin>>A>>B;
  for(int i=1;i<=B;i++){
    if(B==A*i){
      cout<<A+B<<endl;
      return 0;
    }
  }
  cout<<B-A<<endl;
}
