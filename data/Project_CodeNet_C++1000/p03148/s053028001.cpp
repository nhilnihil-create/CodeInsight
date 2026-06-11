#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin>>N>>K;
  vector<pair<int,int64_t>> p(N);
  for(int i=0;i<N;i++){
    int a;
    int64_t b;
    cin>>a>>b;
    p[i]=make_pair(a,b);
  }
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  vector<int64_t> q;
  vector<int64_t> r;
  for(int i=0;i<N;i++){
    if(i==0){
      q.push_back(p[i].second);
    }
    else if(p[i].first!=p[i-1].first){
      q.push_back(p[i].second);
    }
    else{
      r.push_back(p[i].second);
    }
  }
  q.push_back(-167167167167167);
  r.push_back(-167167167167167);
  q.push_back(167167167167167);
  r.push_back(167167167167167);
  sort(q.begin(),q.end());
  reverse(q.begin(),q.end());
  sort(r.begin(),r.end());
  reverse(r.begin(),r.end());
  int M=q.size();
  int L=r.size();
  q[0]=0;
  r[0]=0;
  for(int i=1;i<M;i++){
    q[i]+=i*2-1;
    q[i]+=q[i-1];
  }
  for(int i=1;i<L;i++){
    r[i]+=r[i-1];
  }
  int64_t Z=0;
  for(int i=0;i<=min(K,M-1);i++){
    if(!(K-i>=L||K-i<0)){
      Z=max(Z,q[i]+r[K-i]);
    }
  }
  cout<<Z<<endl;
}