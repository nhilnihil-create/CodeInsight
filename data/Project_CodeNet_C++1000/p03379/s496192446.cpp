#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  rep(i,n){
    cin >> x[i];
    y[i] = x[i];
  }
  sort(x.begin(),x.end());
  int mid_a = x[n/2 - 1];
  int mid_b = x[n/2];
  rep(i,n){
    if(y[i] < mid_b) cout << mid_b << endl;
    else cout << mid_a << endl;
  }
  return 0;
}
