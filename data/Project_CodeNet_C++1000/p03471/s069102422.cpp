#include<iostream>
using namespace std;
int main(){
  int n,y;
  cin>>n>>y;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      int k=y-i*10000-j*5000;
      if(k%1000==0){
        int q=k/1000;
        if(i+j+q==n&&q>=0){
          cout<<i<<" "<<j<<" "<<q<<endl;
          return 0;
        }
      }
    }
  }
  cout<<-1<<" "<<-1<<" "<<-1<<endl;
  return 0;
}