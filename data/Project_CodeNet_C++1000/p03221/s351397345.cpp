#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  pair<long long,pair<long long,int>> P[100000];
  for(int i=0;i<M;i++){
    long long p,y;
    cin>>p>>y;
    P[i]=make_pair(p,make_pair(y,i));
  }
  sort(P,P+M);
  long long A[100000];
  int num=1;
  for(int i=0;i<M;i++){
    if(i!=0&&P[i].first!=P[i-1].first) num=1;
    int n=P[i].second.second;
    A[n]=1000000*P[i].first+num;
    num++;
  }
  for(int i=0;i<M;i++){
    int judge=0;
    long long X=A[i];
    while(X>=1000000){
      X/=10;
      judge++;
    }
    for(int j=0;j<6-judge;j++) cout<<0;
    cout<<A[i]<<endl;
  }
  
  return 0;
}