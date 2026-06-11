#include <bits/stdc++.h>
using namespace std;

int N,M,Q;

//累積和
vector<vector<int>> sum;
int buildSumTable(vector<int>L, vector<int>R){
  sum=vector<vector<int>>(N+1,vector<int>(N+1,0));
  //大きい長方形を求めるときに長方形+長方形-被っているところ+四角形ってやるよねって式
  for (int i=0;i<M;++i){
    sum[L[i]][R[i]]++;
  }

  for (int i=1;i<=N;++i){
    for (int j=1;j<=N;++j){
      sum[i][j]+=sum[i-1][j];
      sum[i][j]+=sum[i][j-1];
      sum[i][j]-=sum[i-1][j-1];
    }
  } 
}

int getSumRange(int L, int R){
  //大きい長方形を求めるときに長方形+長方形-被っているところ+四角形ってやるよねって式
  int ans=sum[R][R]-sum[R][L-1]-sum[L-1][R]+sum[L-1][L-1];
  return ans;
}

int main(){
  cin >> N >> M >> Q;
  vector<int> L(M);
  vector<int> R(M);
  for (int i=0;i<M;++i) cin >> L[i] >> R[i];
  vector<int> p(Q);
  vector<int> q(Q);
  for (int i=0;i<Q;++i) cin >> p[i] >> q[i];
  buildSumTable(L,R);
  for (int i=0;i<Q;++i){
    int ans=getSumRange(p[i],q[i]);
    cout << ans << endl;
  }
}
//上級者はセグ木でやるらしい...
//この問題はLとRの軸を垂直に取って長方形を考えることができるかが肝