#include <bits/stdc++.h>
using namespace std;

long N,M;vector<vector<long>> g;

void color(long b,vector<long> &c) {
  for (long x:g[b]) {
    if (c[x]==0L) {
      if (c[b]==1L) c[x]=2L;
      else if (c[b]==2L) c[x]=1L;
      color(x,c);
    }
  }
}

long hantei(vector<long> &c,vector<pair<long,long>> p) {
  long result=0L;
  for (pair<long,long> x:p) {
    long a=x.first;long b=x.second;
    if (c[a]==c[b])  {
      result=-1L;
      break;
    }
  }
  if (result!=-1L) {
    long s=0L,t=0L;
    for (int i=0;i<N;i++) {
      if (c[i]==1L) s++;
      else if(c[i]==2L) t++;
    }
    result=s*t;
  }
  return result;
}

int main() {
  cin >> N >> M;vector<long> c(N,0);
  g.resize(N);vector<pair<long,long>> P(M);
  for (int i=0;i<M;i++) {
    long a,b;cin >> a >> b;a--;b--;
    g[a].push_back(b);g[b].push_back(a);
    P[i]=make_pair(a,b);
  }
  c[0]=1L;
  color(0,c);
  long res=hantei(c,P);
  if (res!=-1L) {
    cout << res-M << endl;
  }
  else {
    cout << N*(N-1L)/2L-M << endl;
  }
}