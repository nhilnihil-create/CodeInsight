#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i) = 0; i < (n); i++)

int main(){
  int a, b, s[4] = {};
  rep(i, 3){
    cin >> a >> b;
    s[a - 1]++;
    s[b - 1]++;
  }
  rep(i, 4) if(s[i] == 3){
    puts("NO");
    return 0;
  }
  puts("YES");
  
}	