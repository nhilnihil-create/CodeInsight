#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
using vi = vector<int>;
using vll = vector<ll>;
const ll INF = 1LL<<60;

int main(){
  int n; cin >> n;
  string ans = "No";
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      int now = 4 * i + 7 * j;
      if(now == n) ans = "Yes";
    }
  }
  cout << ans << endl;
  return 0;
}
