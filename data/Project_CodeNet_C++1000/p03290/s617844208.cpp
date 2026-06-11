#include <bits/stdc++.h>
using namespace std;

int main(){
  int D,G;
  cin>>D>>G;
  vector<vector<int>> A(D,vector<int>(2));
  int l=0;
  for(vector<int> &i:A){
    cin>>i.at(0)>>i.at(1);
    l+=i.at(0);
  }
  for(int tmp=0;tmp<(1<<A.size());tmp++){
    bitset<10> s(tmp);
    int j=0,p=0;
    for(int i=0;i<A.size();i++)
      if(s.test(i)){
        j+=(i+1)*A.at(i).at(0)*100+A.at(i).at(1);
        p+=A.at(i).at(0);
      }
    int o=0;
    int i=D-1;
    for(;s.test(i);i--)
      if(i==0){
        i=-1;
        break;
      }
    if(i==-1){
      l=min(l,p);
      continue;
    }
    int k=0;
    for(;k*(i+1)*100+j<G;k++){}
    if(k>=A.at(i).at(0))
      continue;
    l=min(l,k+p);
  }
  cout<<l<<endl;
}