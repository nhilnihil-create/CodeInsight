#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  vector<pair<int,int>> p(M);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    p.at(i)=make_pair(b,a);
  }
  sort(p.begin(),p.end());
  int Z=1,L=p.at(0).first;
  for(int i=1;i<M;i++){
    if(L<=p.at(i).second){
      L=p.at(i).first;
      Z++;
    }
  }
  cout<<Z<<endl;
}
