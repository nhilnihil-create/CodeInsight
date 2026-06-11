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
  string s,t;
  cin>>s>>t;
  int n=s.size();
  vector<int>S(26,-1),T(26,-1);
  for(int i=0;i<n;i++){
    int l=s[i]-'a',r=t[i]-'a';
    if(S[l]!=-1||T[r]!=-1){
      if(r!=S[l]||l!=T[r]){
        cout<<"No"<<endl;return 0;
      }
    }
    S[l]=r,T[r]=l;
  }
  cout<<"Yes"<<endl;
  return 0;
}