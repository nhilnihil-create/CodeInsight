#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Y,A=-1,B=-1,C=-1;
  cin>>N>>Y;
  Y/=1000;
  for(int i=0;i<=N;i++){
    for(int j=0;j+i<=N;j++){
      if(i*5+j*10+N-i-j==Y){
        A=j,B=i,C=N-i-j;
      }
    }
  }
  cout<<A<<" "<<B<<" "<<C<<endl;
}