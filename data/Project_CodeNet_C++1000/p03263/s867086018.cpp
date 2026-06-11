#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<int>>A(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>A[i][j];
    }
  }

  vector<tuple<int,int,int,int>>p;

  int cnt=0;
  int i=0,j=0;
  for(int r=0;r<H*W-1;r++){
    int a=i,b=j;//一筆書きの経路をa,b->c,dとする
    if(i%2!=0){
      if(j>0){j--;}
      else{i++;}
    }
    else{
      if(j<W-1){j++;}
      else{i++;}
    }
    int c=i,d=j;
    if(A[a][b]%2!=0){
      cnt++;A[a][b]--;A[c][d]++;
      p.push_back(make_tuple(a+1,b+1,c+1,d+1));
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