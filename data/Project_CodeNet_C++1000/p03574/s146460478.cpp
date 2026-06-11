#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>func(int64_t x){
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

int main(){
  int H,W;
  cin>>H>>W;
  char s[1000][1000];
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cin>>s[i][j];
    }
  }
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      int cnt=0;
      if(s[i][j]=='.'){
        if(s[i][j+1]=='#'){cnt++;}
        if(s[i][j-1]=='#'){cnt++;}
        if(s[i+1][j]=='#'){cnt++;}
        if(s[i-1][j]=='#'){cnt++;}
        if(s[i+1][j+1]=='#'){cnt++;}
        if(s[i-1][j-1]=='#'){cnt++;}
        if(s[i-1][j+1]=='#'){cnt++;}
        if(s[i+1][j-1]=='#'){cnt++;}
        s[i][j]=(char)(cnt+'0');
      }
    }
  }
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cout<<s[i][j];
    }
    cout<<endl;
  }
  return 0;
}