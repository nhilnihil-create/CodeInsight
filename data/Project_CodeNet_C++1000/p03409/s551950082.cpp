#include<bits/stdc++.h>
using namespace std;
struct edge{
  long to,cap,rev;//capは残りどれだけ流せるか, revはv[to][rev]が自分への逆辺を表す
  edge(){}
  edge(long t,long c,long r):to(t),cap(c),rev(r){}
};
class flow{
  long n;
  vector<vector<edge>>v;
  vector<bool>used;
  public:
  
  long dfs(long s,long t,long f){
    if(s==t)return f;
    used[s]=1;
    for(long i=0;i<v[s].size();i++){
      edge e=v[s][i];
      if(!used[e.to]&&e.cap>0){
        long r=dfs(e.to,t,min(f,e.cap));
        if(r>0){
          v[s][i].cap-=r;v[e.to][e.rev].cap+=r;
          return r;
        }
      }
    }
    return 0;
  }
  long solve(long s,long t){//最大流を求める
    long ans=0;
    while(1){
      used.clear();used=vector<bool>(n,0);
      long f=dfs(s,t,LONG_MAX);
      if(f==0)return ans;
      else ans+=f;
    }
  }
  flow(){}
  flow(const vector<vector<edge>>&v_)
    :n(v_.size()),v(vector<vector<edge>>(v_.size())){
      for(long i=0;i<n;i++)for(long j=0;j<v_[i].size();j++){
        edge e=v_[i][j];
        v[i].push_back(edge(e.to,e.cap,v[e.to].size()));//辺の追加
        v[e.to].push_back(edge(i,0,v[i].size()-1));//逆辺の追加
      }
    }
};

int main(){
  long N;cin>>N;
  vector<long>a(N),b(N),c(N),d(N);
  for(long i=0;i<N;i++)cin>>a[i]>>b[i];
  for(long i=0;i<N;i++)cin>>c[i]>>d[i];
  vector<vector<edge>>A(2*N+2);
  for(long i=0;i<N;i++){
    A[0].push_back(edge(i+1,1,0));
    A[N+1+i].push_back(edge(2*N+1,1,0));
  }
  for(long i=0;i<N;i++)for(long j=0;j<N;j++){
    if(a[i]<c[j]&&b[i]<d[j])A[i+1].push_back(edge(j+1+N,1,0));
  }
  flow f(A);cout<<f.solve(0,2*N+1);
}