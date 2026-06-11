#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n; cin>>n;
  ll an[n]; rep(i,n) cin >> an[i];
  ll sn[n+1];
  sn[0]=0;rep(i,n)sn[i+1]=sn[i]+an[i];
  sort(sn,sn+n+1);
  ll cnt=0,total=0;
  rep(i,n){
    if (sn[i+1]==sn[i]) {
      cnt++;
      total += cnt;
    } else {
      cnt=0;
    }
  }
  cout<<total;
}
