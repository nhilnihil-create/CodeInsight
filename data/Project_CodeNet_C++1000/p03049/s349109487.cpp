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

const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<string>s(N);
  for(int i=0;i<N;i++){
    cin>>s[i];
  }
  int cnt=0,cntA=0,cntB=0,cntBA=0;
  for(int i=0;i<N;i++){
    int ni=s[i].size();
    if(s[i].back()=='A'&&s[i].front()=='B'){cntBA++;}
    else if(s[i].back()=='A'){cntA++;}
    else if(s[i].front()=='B'){cntB++;}
    for(int j=0;j<ni;j++){
      if(s[i].substr(j,2)=="AB"){cnt++;}
    }
  }
  if(cntA==0&&cntB==0&&cntBA>0){cout<<cnt+cntBA-1<<endl;}
  else{cout<<cnt+min(cntBA+cntA,cntBA+cntB)<<endl;}
  
  return 0;
}