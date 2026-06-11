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

string t,s;
int S,T;

bool match(int k){
  for(int i=0;i<T;i++){
    if(t[i]!=s[i+k]&&s[i+k]!='?'){
      return false;
    }
  } 
  return true;
}

string construct(int k){
  string ans=s; 
  for(int i=0;i<T;i++){
    ans[k+i]=t[i];
  }
  for(int i=0;i<S;i++){
    if(ans[i]=='?'){ans[i]='a';}
  }
  return ans;
}

int main() {
  cin>>s>>t;
  S=s.size(),T=t.size();
  vector<string>table;
  //table.push_back("000");
  if(S<T){cout<<"UNRESTORABLE"<<endl;return 0;}
  bool ok=false;
  for(int i=0;i<=S-T;i++){
    if(match(i)){ok=true;table.push_back(construct(i));}
  }
  if(!ok){cout<<"UNRESTORABLE"<<endl;return 0;}
  sort(table.begin(),table.end());
  cout<<table[0]<<endl;
  return 0;
}