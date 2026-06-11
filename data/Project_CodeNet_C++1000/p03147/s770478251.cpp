#include<iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  int h[N];
  for(int i=0; i<N; i++) cin >> h[i];
  int x, count, sum=0, zeros=0;
  while(zeros<N){
    count = 0;
    x = 0;
    zeros=0;
    for(int i=0; i<N; i++){
      if(x==0 && h[i]>0) count++;
      x = h[i];
      if(h[i]>0) h[i]--;
      else zeros++;
    }
    sum += count;
  }
  
  cout<<sum<<endl;
  
  return 0;
}