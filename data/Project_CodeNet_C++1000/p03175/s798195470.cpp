#include<bits/stdc++.h>
#define int long long
using namespace std;
using P=pair<int,int>;
const int mod=1000000007;
P a(vector<vector<int>> &A,vector<bool> &B,int n){
  int w=1,b=1;
  for(int i:A[n])
    if(B[i]){
      B[i]=false;
      P p=a(A,B,i);
      w=w*((p.first+p.second)%mod)%mod;
      b=b*p.first%mod;
    }
  return {w,b};
}
signed main(){
  int N;
  cin>>N;
  vector<vector<int>> A(N);
  for(int i=1;i<N;i++){
    int a,b;
    cin>>a>>b;
    A[a-1].push_back(b-1);
    A[b-1].push_back(a-1);
  }
  vector<bool> B(N,true);
  B[0]=false;
  P C=a(A,B,0);
  cout<<(C.first+C.second)%mod<<endl;
}