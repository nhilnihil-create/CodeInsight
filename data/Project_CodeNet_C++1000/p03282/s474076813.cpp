#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  string s;
  cin>>s;
  int64_t K;
  cin>>K;
  K--;
  int st=0;
  for(int i=0;i<s.size();i++){
    if(s[i]!='1'){st=i;break;}
  }
  if(st<=K){cout<<s[st]<<endl;}
  else{cout<<1<<endl;}
  return 0;  
}