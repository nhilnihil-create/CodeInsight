#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >>N;
  int count=0;
  for(int a=0;a<=N/4;a++){
    for(int b=0;b<=N/7;b++){
      int sum=4*a+7*b;
      if (sum==N){
        count++;
      }
    }
  }
  if(count!=0){ 
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
    
}
