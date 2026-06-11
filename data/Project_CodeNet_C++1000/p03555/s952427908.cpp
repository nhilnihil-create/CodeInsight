#include<bits/stdc++.h>
using namespace std;

int main(){
  char a[7];
  for(int i=0;i<6;i++){
    cin>>a[i];
  }
  if(a[0]==a[5]&&a[1]==a[4]&&a[2]==a[3]){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}