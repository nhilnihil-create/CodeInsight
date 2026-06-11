#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int d,n;
  cin>>d>>n;
  if(n==100){
    if(d==0){
    cout<<n+1<<endl;
  }else if(d==1){
    cout<<100*n+100<<endl;
  }else{
    cout<<100*100*n+10000<<endl;
  }
  } else{
  if(d==0){
    cout<<n<<endl;
  }else if(d==1){
    cout<<100*n<<endl;
  }else{
    cout<<100*100*n<<endl;
  }
    }
}