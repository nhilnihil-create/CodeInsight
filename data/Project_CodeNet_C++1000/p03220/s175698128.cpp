#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,T,A;
  cin>>N>>T>>A;
  vector<int> h(N);
  for(int i=0;i<N;i++)
    cin>>h.at(i);
  T*=1000;
  A*=1000;
  int dif=A-T+6*h.at(0),index=0;
  if(dif<0)
    dif=-dif;
  for(int i=0;i<N;i++){
    int a=A-T+6*h.at(i);
    if(a<0)
      a=-a;
    if(a<dif){
      dif=a;
      index=i;
    }
  }
  cout<<index+1<<endl;
}