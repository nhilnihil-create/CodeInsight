#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main(){
  ll x,y,c;
  cin >> x >> y;
  ll s=x;
  c=0;
  while(s<=y){
    s=2*s;
    c++;
  }
  cout << c << endl;
}