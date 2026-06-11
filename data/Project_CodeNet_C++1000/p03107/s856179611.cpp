#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  
  int cnt=0;
  int n=s.size();
  rep(i,n){
    if(s[i]=='0') cnt++;
  }
  
  cout<<2*min(cnt,n-cnt)<<endl;
  
  return 0;
}