#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD =1e9+7;
using ll=long long;
int n, m;
int d, t;
map<int, int> D, T;
int main(){
  cin >> n;
  rep(i,n){
    cin >> d;
    D[d]++;
  }
  cin >> m;
  rep(i,m){
    cin >> t;
    T[t]++;
  }
  string ans = "YES";
  for(auto p: T){
    int score = p.first;
    int cnt = p.second;
    if(D[score] < cnt) ans = "NO";
  }
  cout << ans << endl;
}
