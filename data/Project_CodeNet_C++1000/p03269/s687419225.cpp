#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct edge{ll from,to,cost;};
ll L;
int main(){
  cin>>L;L--;
  vector<edge>A;
  ll a=0;ll b=1;
  while(b<=L+1){b*=2;a++;}ll X=L;
  for(int  i=1;i<=a-1;i++){
  if(X%2==0){
  edge e;e.from=i;e.to=a;e.cost=X;
    A.push_back(e);
     edge e1;e1.from=i;e1.to=i+1;e1.cost=X/2;
    A.push_back(e1);
     edge e2;e2.from=i;e2.to=i+1;e2.cost=0;
    A.push_back(e2);
    X/=2;X--;
  }else{
   edge e1;e1.from=i;e1.to=i+1;e1.cost=(X+1)/2;
    A.push_back(e1);
     edge e2;e2.from=i;e2.to=i+1;e2.cost=0;
    A.push_back(e2);
    X/=2;
  }
    if(X==0)break;
   }ll M=A.size();
  cout<<a<<" "<<M<<endl;
  for(int i=0;i<M;i++)
    cout<<A[i].from<<" "<<A[i].to<<" "<<A[i].cost<<endl;
  return 0;
}