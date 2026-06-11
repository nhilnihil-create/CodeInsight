#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1e18;

int main(){
  int n,m,X,Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n);
  vector<int> y(m);
  rep(i,n) cin >> x[i];
  rep(i,m) cin >> y[i];

  sort(x.begin(),x.end());
  sort(y.begin(),y.end());

  int x_max = *x.rbegin();
  int y_min = *y.begin();

  for(int i=-100; i<=100; i++){
    if(X<i&&i<=Y&&x_max<i&&i<=y_min){
      cout << "No War" << endl;
      return 0;
    }
  }

  cout << "War" << endl;

  return 0;
}