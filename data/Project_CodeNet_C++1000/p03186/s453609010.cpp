#include<bits/stdc++.h>
using namespace std;
int main(){
  long long A,B,C;
  cin>>A>>B>>C;
  if(C<=B+A){
    cout<<C+B<<endl;
  }
  else{
    cout<<A+2*B+1<<endl;
  }
}
