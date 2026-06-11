#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string s,t;
  cin >> s >> t;
  if(s[0] == t[2]){
    if(s[1] == t[1]){
      if(s[2] == t[0]){
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
