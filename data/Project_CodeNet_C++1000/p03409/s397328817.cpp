#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<pair<int,int>> A(N),B(N);
  for(pair<int,int> &i:A)
    cin>>i.first>>i.second;
  A.push_back(make_pair(-1,-1));
  for(pair<int,int> &i:B)
    cin>>i.first>>i.second;
  sort(B.begin(),B.end());
  set<int> a;
  for(int i=0;i<N;i++)
    a.insert(i);
  int l=0;
  for(int i=0;i<N;i++){
    set<int> C;
    for(int j:a)
      if(A[j].first<B[i].first && A[j].second<B[i].second)
        C.insert(j);
    if(C.size()==0)
      continue;
    int k=N;
    for(int j:C)
      if(A[k].second<A[j].second)
        k=j;
    a.erase(k);
    l++;
  }
  cout<<l<<endl;
}