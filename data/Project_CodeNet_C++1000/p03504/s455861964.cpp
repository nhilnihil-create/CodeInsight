#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,C,Z=0;
  cin>>N>>C;
  vector<vector<int>> p(100001,vector<int>(C));
  for(int i=0;i<N;i++){
    int a,b,c;
    cin>>a>>b>>c;
    c--;
    p.at(a).at(c)++;
    p.at(b).at(c)--;
  }
  vector<int> q(200001);
  for(int i=0;i<C;i++){
    for(int j=1;j<100001;j++){
      if(p.at(j).at(i)==1){
        q.at(j*2-1)++;
      }
      if(p.at(j).at(i)==-1){
        q.at(j*2)--;
      }
    }
  }
  for(int i=1;i<=200000;i++){
    q.at(i)+=q.at(i-1);
    Z=max(Z,q.at(i));
  }
  cout<<Z<<endl;
      
}