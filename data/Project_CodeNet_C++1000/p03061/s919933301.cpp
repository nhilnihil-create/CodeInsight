#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  vector<int>L(N+2,1);
  vector<int>R(N+2,1);
  int g=A[0];
  for(int i=0;i<N;i++){
    g=__gcd(A[i],g);
    L[i]=g;
  }
  g=A[N-1];
  for(int i=N-1;i>=0;i--){
    g=__gcd(A[i],g);
    R[i]=g;
  }
  int MAX=1;
  for(int i=0;i<N;i++){
    if(i==0){chmax(MAX,R[i+1]);}
    else if(i==N-1){chmax(MAX,L[i-1]);}
    else {chmax(MAX,__gcd(L[i-1],R[i+1]));}
  }
  cout<<MAX<<endl;
  return 0;
}