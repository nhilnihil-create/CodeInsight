#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> RA;
vector<int64_t> cou;
int root(int a){
  if(a==par[a]){
    return a;
  }
  else{
    return par[a]=root(par[a]);
  }
}
void UN(int a,int b){
  a=root(a);
  b=root(b);
  if(a==b){
    return;
  }
  int A=cou[a];
  int B=cou[b];
  cou[a]=A+B;
  cou[b]=A+B;
  if(RA[a]<RA[b]){
    par[a]=b;
  }
  else{
    par[b]=a;
  }
  if(RA[a]==RA[b]){
    RA[a]++;
  }
}
bool same(int a,int b){
  if(root(a)==root(b)){
    return true;
  }
  else{
    return false;
  }
}


int main(){
  int64_t N,M;
  cin>>N>>M;
  vector<pair<int,int>> p(M);
  for(int i=M-1;i>=0;i--){
    int a,b;
    cin>>a>>b;
    a--,b--;
    p[i]=make_pair(a,b);
  }
  int64_t Z=N*(N-1)/2;
  par.resize(N);
  RA.resize(N);
  cou.resize(N);
  for(int i=0;i<N;i++){
    par[i]=i;
    RA[i]=1;
    cou[i]=1;
  }
  vector<int64_t> ans(M);
  ans[0]=Z;
  for(int i=0;i<M-1;i++){
    int a,b;
    tie(a,b)=p[i];
    if(!same(a,b)){
      Z-=cou[root(a)]*cou[root(b)];
      UN(a,b);
    }
    ans[i+1]=Z;
  }
  for(int i=M-1;i>=0;i--){
    cout<<ans[i]<<endl;
  }
}
  