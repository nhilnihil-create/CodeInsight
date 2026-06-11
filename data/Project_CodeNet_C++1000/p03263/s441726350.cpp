#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
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
  vector<vector<int>>a(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>a[i][j];
    }
  }

  vector<tuple<int,int,int,int>>p;

  int cnt=0;
  for(int i=0;i<H;i++){
    if(i%2!=0){
      for(int j=W-1;j>=0;j--){
          if(i==H-1&&j==0){continue;}
          if(a[i][j]%2!=0){  
            a[i][j]--;cnt++;
            if(j>0){a[i][j-1]++;p.push_back(make_tuple(i+1,j+1,i+1,j));}
            else {a[i+1][j]++;p.push_back(make_tuple(i+1,j+1,i+2,j+1));}
          }
      }
    }
    else{
      for(int j=0;j<W;j++){
          if(i==H-1&&j==W-1){continue;}
          if(a[i][j]%2!=0){
            a[i][j]--;cnt++;
            if(j<W-1){a[i][j+1]++;p.push_back(make_tuple(i+1,j+1,i+1,j+2));}
            else {a[i+1][j]++;p.push_back(make_tuple(i+1,j+1,i+2,j+1));}
          }
      }
    }
  }
  cout<<cnt<<endl;
  for(auto k:p){
    int a,b,c,d;
    tie(a,b,c,d)=k;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl; 
  }
  return 0;  
}