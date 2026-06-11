#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

class UnionFind{
public:
  vector<int> parent;
  UnionFind(int N){
    parent=vector<int>(N,-1);
  }
  int root(int A){
      if(parent[A]<0) return A;
      return parent[A]=root(parent[A]);
  }
  int size(int A){
    return -parent[root(A)];
  }
  bool connect(int A,int B){
    A=root(A);
    B=root(B);
    if(A==B){
      return false;
    }
    if(size(A)<size(B))swap(A,B);
    parent[A]+=parent[B];
    parent[B]=A;
    return true;
  }
};

signed main(){
  int N,M;
  cin>>N>>M;
  vector<int> A(M),B(M);
  rep(i,M){
    cin>>A[i]>>B[i];
    A[i]--;
    B[i]--;
  }
  vector<int> ans(M);
  ans[M-1]=N*(N-1)/2;
  UnionFind uni(N);
  for(int i=M-1;i>=1;i--){
    ans[i-1]=ans[i];
    if(uni.root(A[i])!=uni.root(B[i])){
      ans[i-1]-=uni.size(A[i])*uni.size(B[i]);
      uni.connect(A[i],B[i]);
    }
  }
  rep(i,M){
    cout<<ans[i]<<endl;
  }
}