#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  vector<vector<char>> a(2,vector<char>(3));
   
  rep(i,2)rep(j,3) cin >> a.at(i).at(j);

  bool  ans = true;
  rep(i,3){
    if(a.at(0).at(i) != a.at(1).at(2-i)) ans = false;
  }
  puts(ans?"YES":"NO");
}