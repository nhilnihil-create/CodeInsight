#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  if(N>30){
    cout<<"Yes"<<endl;
  }
  else{
    for(int i=0;i<=N/7;i++){
      if((N-7*i)%4==0){
        cout<<"Yes"<<endl;
        break;
      }
      else if(i==N/7){
        cout<<"No"<<endl;
      }
    }
  }
}