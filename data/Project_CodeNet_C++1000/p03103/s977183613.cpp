#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> ab(n);
  rep(i,n){
   int a, b;
   cin >> a >> b;
    ab[i].first = a;
    ab[i].second = b;
  }
  sort(ab.begin(),ab.end());
  ll ans = 0;
  int hon = 0;
  int i=0;
  while(hon < m){
    hon++;
    ans += ab[i].first;
    ab[i].second --;
    if(ab[i].second == 0) i++;
  }
  cout << ans << endl;
}
