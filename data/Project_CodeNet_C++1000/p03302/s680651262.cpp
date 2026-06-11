#include<bits/stdc++.h>
using namespace std;

int main(){
 long long N,u,c,ans;
  cin>>N>>c;
  if(N+c==15){
  cout<<'+'<<endl;
  }
  else if(N*c==15){
  cout<<'*'<<endl;
  }
  else{
  cout<<"x"<<endl;
  }
}
