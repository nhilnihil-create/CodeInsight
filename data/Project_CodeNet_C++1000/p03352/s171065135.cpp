#include<bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin>>x;
  int tmp=1;
  int MAX=1;
  for(int i=2;i<=x;i++){
    int j=2;
    while(true){
      if(pow(i,j)<=x){
        //cout<<pow(i,j)<<endl;
        MAX=max(MAX,(int)pow(i,j));
        j++;
      }else{
        break;
      }
    }
  }
  cout<<MAX<<endl;
}