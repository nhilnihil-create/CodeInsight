#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  if(N%2==0){
    cout<<N<<endl;
  }
  else if(N==1){
    cout<<2<<endl;
  }
  else{
    cout<<2*N<<endl;
  }
}