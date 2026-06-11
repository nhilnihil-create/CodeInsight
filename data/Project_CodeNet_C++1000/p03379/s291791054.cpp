#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<ll> x(n);
  rep(i,n) cin >> x.at(i);

  vector<ll> y(n);
  rep(i,n) y.at(i) = x.at(i);
  sort(y.begin(), y.end());

  ll mid_l=y.at(n/2-1), mid_r=y.at(n/2);
  rep(i,n){
    if(x.at(i)<mid_r) cout << mid_r << endl;
    else cout << mid_l << endl;
  }
}