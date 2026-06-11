#include<iostream>
using namespace std;
#define MAXN 500

int N;
int C[MAXN],S[MAXN],F[MAXN];

int main(){
  cin>>N;
  for(int i=0;i<N-1;i++){
    cin>>C[i]>>S[i]>>F[i];
  }
  for(int i=0;i<N-1;i++){
    int cnt=i;
    int time=0;
    while(cnt<=N-2){
      if(time<=S[cnt]) time=S[cnt];
      else time=S[cnt]+((time-S[cnt]+F[cnt]-1)/F[cnt])*F[cnt];
      time+=C[cnt];
      cnt++;
    }
    cout<<time<<endl;
  }
  cout<<0<<endl;
  return 0;
}