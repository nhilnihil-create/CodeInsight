#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

int main() {
  int N,M;
  cin>>N>>M;
  vector<int>A(N);
  priority_queue<pair<int,int>>s;
  for(int i=0;i<N;i++){
    cin>>A[i];
    s.push(make_pair(A[i],1));
  }
  vector<int>B(M),C(M);
  for(int i=0;i<M;i++){
    cin>>B[i]>>C[i];
    s.push(make_pair(C[i],B[i]));
  }
  int64_t ans=0;
  for(int i=0;i<N;i++){
    auto p=s.top();
    s.pop();
    ans+=p.first;
    if(p.second>1){
      p.second--;
      s.push(p);
    }
  }
  cout<<ans<<endl;
  return 0;
}