#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int n; cin >> n;
  vector<int> l(n);
  rep(i,n){
    cin >> l[i];
  }
  int sum = 0;
  sort(l.begin(), l.end());
  rep(i,n-1){
    sum += l[i];
  }
  if(sum > l[n-1]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
