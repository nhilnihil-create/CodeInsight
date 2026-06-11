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
  vector<int>A(N),B(N);
  vector<pair<int,int>>P(N);
  for(int i=0;i<N;i++){
    cin>>A[i]>>B[i];
    P[i]=make_pair(A[i],B[i]);
  }
  sort(P.begin(),P.end());
  int64_t cost=0,tot=M;
  for(int i=0;i<N;i++){
    int64_t p=P[i].first;
    int64_t q=P[i].second;
    if(tot>=q){cost+=p*q;tot-=q;}
    else if(tot<q){cost+=p*tot;tot-=tot;break;}
    //cout<<cost<<endl;
  }
  cout<<cost<<endl;
  return 0;
}