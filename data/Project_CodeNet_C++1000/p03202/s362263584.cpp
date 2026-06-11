#include<bits/stdc++.h>
using namespace std;
vector<int>A;
int check(int x){
  if(x==1)return is_sorted(A.begin(),A.end());
  map<int,int>m;
  for(int i=1;i<A.size();i++){
    if(A[i-1]<A[i])continue;
    if(m.upper_bound(A[i])!=m.end())
    m.erase(m.upper_bound(A[i]));
    int k=A[i];
    m[k]++;
    while(k>0&&m[k]==x)m.erase(k),m[--k]++;
    if(k==0)return false;
  }
  return true;
}
int main(void){
  int N;cin>>N;
  A.resize(N);
  for(int &a:A)cin>>a;
  int l=0,h=N;
  while(h-l>1){
    int m=(l+h)/2;
    if(check(m))h=m;
    else l=m;
  }
  cout<<h<<endl;
}
