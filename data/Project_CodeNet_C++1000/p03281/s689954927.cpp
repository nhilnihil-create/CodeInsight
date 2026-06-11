#include <bits/stdc++.h>
using namespace std;

int yakusuu(int N){
  int count=0;
  for(int i=1;i<N+1;i++){
    if(N%i==0){
      count++;
      if(N/i==i){
        count++;
      }
    }
  }
  return count;
}
         
int main(){
  int N,count=0;
  cin >> N;
  for(int i=1;i<N+1;i+=2){
    if(yakusuu(i)==8){
      count++;
    }
  }
  cout << count << endl;
}