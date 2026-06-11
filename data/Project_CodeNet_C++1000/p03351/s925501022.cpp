#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(d >= abs(a-b) && d >= abs(c-b)){
    puts("Yes");
  }
  else if(d >= abs(a-c)){
    puts("Yes");
  }
  else puts("No");
  return 0;
}
