#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin>>s;
  
  int n=s.size();
  
  int a=0,b=0;
  rep(i,n){
    if(i%2==1){
      if(s[i]=='0') b++;
      else a++;
    }
    else{
      if(s[i]=='1') b++;
      else a++;
    }
  }
    
  cout<<min(a,b)<<endl;    
  
  return 0;
}