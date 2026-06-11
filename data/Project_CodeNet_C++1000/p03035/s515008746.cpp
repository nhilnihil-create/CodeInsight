#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  int a,b; cin >> a >> b;

  if(a <= 5) cout << 0 << endl;
  else if(6 <= a && a <= 12) cout << b/2 << endl;
  else cout << b << endl;
  return 0;
}
