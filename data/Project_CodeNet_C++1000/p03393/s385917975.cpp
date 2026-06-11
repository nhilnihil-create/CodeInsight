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
  string s;
  cin>>s;
  int n=s.size();
  bool use[26][26];
  for(int i=0;i<26;i++){
    for(int j=0;j<26;j++){
      use[i][j]=true;
    }
  }
  vector<bool>ok(26,true);
  for(int i=0;i<n;i++){
    ok[s[i]-'a']=false;
    for(int j=0;j<26;j++){
      use[i][j]=ok[j];
    }
  }
  string t=s;
  if(t.size()<26){
    char y;
    bool r=false;
    for(int j=0;j<26;j++){
      if(use[n-1][j]){y=(char)(j+'a');r=true;break;}
    }
    if(r){t.push_back(y);cout<<t<<endl;return 0;}
  }
  
  for(int i=n-1;i>=0;i--){
    for(int j=s[i]-'a';j<26;j++){
      if(use[i][j]){t[i]=(char)(j+'a');cout<<t.substr(0,i+1)<<endl;return 0;}
    }
  }
  cout<<-1<<endl;
  return 0;
}