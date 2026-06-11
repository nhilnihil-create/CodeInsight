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
  int H,W;
  cin>>H>>W;
  int c[10][10];
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cin>>c[i][j];
    }
  }
  int A[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>A[i][j];
    }
  }
  for(int k=0;k<10;k++){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
      }
    }
  }
  int sum=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A[i][j]>=0){sum+=c[A[i][j]][1];}
    }
  }
  cout<<sum<<endl;
  return 0;
}