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
  int N;
  cin>>N;
  vector<int>A(N),B(N);
  vector<tuple<int,int,int>>p(N);
  for(int i=0;i<N;i++){
    cin>>A[i]>>B[i];
    p[i]=make_tuple(A[i]+B[i],A[i],B[i]);
  }
  sort(p.rbegin(),p.rend());
  int64_t sumt=0,suma=0;
  for(int i=0;i<N;i++){
    int s,t,a;
    tie(s,t,a)=p[i];
    if(i%2==0){
      sumt+=t;
    }
    else{
      suma+=a;
    }
  }
  cout<<sumt-suma<<endl;
  return 0;
}