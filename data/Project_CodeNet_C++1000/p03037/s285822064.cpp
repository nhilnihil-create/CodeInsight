#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n, m;
  cin >> n >> m;

  int l = 1, r = n;
  rep(i,m){
    int li, ri;
    cin >> li >> ri;
    l = max(l, li);
    r = min(r, ri);
  }
  int ans = r - l + 1;
  cout << (ans > 0 ? ans : 0) << endl;
  return 0;
}
