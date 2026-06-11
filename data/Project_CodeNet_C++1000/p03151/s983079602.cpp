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
const int MOD=1000000007;

int main() {
  int N;
  cin>>N;
  vector<int>A(N),B(N);
  int64_t sumA=0,sumB=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    sumA+=A[i];
  }
  for(int i=0;i<N;i++){
    cin>>B[i];
    sumB+=B[i];
  }
  if(sumA<sumB){cout<<-1<<endl;return 0;}

  int64_t need=0,ans=0;
  vector<int>amari;
  for(int i=0;i<N;i++){
    if(A[i]<B[i]){need+=B[i]-A[i];ans++;}
    else if(A[i]>B[i]){amari.push_back(A[i]-B[i]);}
  }
  if(need==0){cout<<0<<endl;return 0;}

  sort(amari.rbegin(),amari.rend());
  int cnt=0;
  for(int i=0;i<amari.size();i++){
    if(amari[i]>=need){cnt++;break;}
    else{need-=amari[i];cnt++;}
  }
  ans+=cnt;

  cout<<ans<<endl;
  return 0;
}