#include<iostream>
using namespace std;
int main(){
  int N;
  cin>>N;
  int cards[N];
  int i;
  for(i=0;i<=N-1;i++){
  cin>>cards[i];
  }
  int Apoints=0;
  int Bpoints=0;
  int max=0;
  int turn=0;
  int maxnum=0;
  while(turn<N){
    turn++;
    max=0;
    maxnum=0;
    for(i=0;i<=N-1;i++){
      if(max<cards[i]){
        max=cards[i];
        maxnum=i;
      }
    }
    if(turn%2==1){
    Apoints+=max;
    }
    else if(turn%2==0){
    Bpoints+=max;
    }
    cards[maxnum]=0;
  }
  cout<<Apoints-Bpoints;
}