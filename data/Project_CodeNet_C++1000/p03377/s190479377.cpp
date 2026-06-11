#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(c >= a && (c-a) <= b){
    puts("YES");
    return 0;
  }
  puts("NO");
  return 0;
}
