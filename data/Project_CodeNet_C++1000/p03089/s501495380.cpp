#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Z=0;
  cin>>N;
  vector<int> p(N);
  vector<int> q(N);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    p[i]=a;
    q[i]=a-1;
  }
  vector<int> ans;
  for(int i=0;i<N;i++){
    for(int j=N-1;j>=0;j--){
      if(q[j]==j){
        ans.push_back(p[j]);
        Z++;
        for(int k=j;k<N;k++){
          q[k]++;
        }
        q[j]=-200;
        break;
      }
    }
  }
  if(Z!=N){
    cout<<"-1"<<endl;
  }
  else{
    for(int i=N-1;i>=0;i--){
      cout<<ans[i]<<endl;
    }
  }
}