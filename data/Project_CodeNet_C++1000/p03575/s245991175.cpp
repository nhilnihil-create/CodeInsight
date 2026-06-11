#include <bits/stdc++.h>
using namespace std;
 
void a(vector<set<int>> &B,vector<bool> &C,int k){
  if(C[k])
    return;
  C[k]=true;
  for(int i:B[k])
    a(B,C,i);
}

int main(){
  int N,M,l=0;
  cin>>N>>M;
  using pii=pair<int,int>;
  vector<pii> A(M);
  for(pii &i:A){
    int j,k;
    cin>>j>>k;
    i=make_pair(j-1,k-1);
  }
  for(pii &i:A){
    vector<set<int>> B(N);
    for(pii j:A){
      if((i.first!=j.first || i.second!=j.second)&&(i.first!=j.second || i.second!=j.first)){
        B[j.first].insert(j.second);
        B[j.second].insert(j.first);
      }
    }
    vector<bool> C(N,false);
    a(B,C,0);
    bool bo=true;
    for(bool b:C){
      bo=bo&&b;
    }
    if(!bo)
      l++;
  }
  cout<<l<<endl;
}