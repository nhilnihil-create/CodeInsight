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
  int a,b; cin >> a >> b;
  vector<int> t(999);
  t[0] = 1;
  for(int i = 2; i <= 999; i++){
    t[i-1] = t[i-2] + i;
  }
  int c = b - a;

  cout << t[c-1] - b << endl;
  return 0;
}
