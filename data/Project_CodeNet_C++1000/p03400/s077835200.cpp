#include<bits/stdc++.h>
using namespace std;

int main (){
  int N,D,X;
  cin >> N >> D >> X;
  int sum=0;
  
  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    for (int j=0;j<100;j++){
      if(j*a+1 <= D){
        sum++;
      }
      else{
        break;
      }
    }
  }
  
  cout << sum+X << endl;
  
}