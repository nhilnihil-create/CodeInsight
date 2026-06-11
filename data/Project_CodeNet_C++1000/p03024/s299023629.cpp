#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  string s;
  cin >> s;
  int k = s.size();
  int cnt = 0;
  rep(i, k){
    if(s.at(i) == 'o')
      cnt++;
  }
  if(8 - cnt <= 15 - k)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}