#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  if(s[0] != s[1]){
    if(s[1] != s[2]){
      if(s[2] != s[0]){
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}
