#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,M,X;
  cin>>N>>M>>X;
  vector<int> n(N+1);
  vector<int> m(M);
  for(int i=0;i<M;i++){
    cin>>m[i];
  }
  for(int i=0;i<=N;i++){
    n[i]=0;
  }
  int ans1=0;
  int ans2=0;
  for(int i=0;i<M;i++){
    n[m[i]]=1;
  }
  for(int i=X;i<=N;i++){
    ans1+=n[i];
  }
  for(int i=0;i<=X;i++){
    ans2+=n[i];
  }
  if(ans1>=ans2){
    cout<<ans2<<endl;
  }
  if(ans1<ans2){
    cout<<ans1<<endl;
  }
}