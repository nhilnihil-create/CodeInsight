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
  int64_t suma=0,sumb=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    suma+=A[i];
  }
  for(int i=0;i<N;i++){
    cin>>B[i];
    sumb+=B[i];
  }
  if(suma<sumb){cout<<-1<<endl;return 0;}
  int64_t r=0,cnt=0;
  vector<int64_t>bag;
  for(int i=0;i<N;i++){
    if(A[i]<B[i]){r+=B[i]-A[i];cnt++;}
    if(A[i]>B[i]){bag.push_back(A[i]-B[i]);}
    //cout<<cnt<<endl;
  }
  sort(bag.rbegin(),bag.rend());
  for(int i=0;i<bag.size();i++){
    if(r<=0){break;}
    cnt++;r-=bag[i];//cout<<bag[i]<<endl;
  }
  cout<<cnt<<endl;
  return 0;
}