#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Z=0;
  cin>>N;
  vector<tuple<int,int,int>> p(2*N);
  for(int i=0;i<N*2;i++){
    int a,b;
    cin>>a>>b;
    p.at(i)=make_tuple(a,b,i/N);
  }
  vector<int> q(2*N);
  sort(p.begin(),p.end());
  for(int i=0;i<2*N;i++){
    int a,b,c;
    tie(a,b,c)=p.at(i);
    if(c==0){
      q.at(b)++;
    }
    else{
      for(int j=b;j>=0;j--){
        if(q.at(j)==1){
          Z++;
          q.at(j)=0;
          break;
        }
      }
    }
  }
  cout<<Z<<endl;
}
