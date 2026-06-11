#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int f(int x){
  int cnt=0;
  for(int i=1;i<=x;i++){
    if(x%i==0){cnt++;}
  }
  return cnt;
}

int main() {
  string s;
  cin>>s;
  int n=s.size();
  int MAX=0;
  string t="AGCT";
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      bool ok=false;  
      for(int v=0;v<4;v++){
        if(s[j]==t[v]){ok=true;}
      }
      if(!ok){break;}
      else{chmax(MAX,j-i+1);}
    }
  }
  cout<<MAX<<endl;
  return 0;  
}