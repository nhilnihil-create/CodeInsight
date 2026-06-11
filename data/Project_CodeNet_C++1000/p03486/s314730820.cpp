#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

bool func(int x){
  int temp = x;
  int y = 0;
  while(temp){
    y += temp%10;
    temp /= 10;
  }
  if(x % y == 0) return true;
  return false;
}

int main(){
  string s,t; cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());

  if(s < t) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
