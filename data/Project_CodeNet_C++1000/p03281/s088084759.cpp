#include<bits/stdc++.h>
using namespace std;

int  yakusuu(int A){
  int count=0;
  for(int i=1;i*i<=A;i++){
    if(A%i==0){
      count++;
      if(A/i!=i){
        count++;
      }
    }
  }
  return count ;
}
    
int main(){
  int N,count=0;
  cin >> N;
 for(int i=0;i<N;i+=2){
    int C=yakusuu(i+1);
    if(C==8){
      count++;
    }
  }
  cout << count << endl;
}