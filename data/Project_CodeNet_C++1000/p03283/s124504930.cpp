#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,m,Q;
  cin >> n >> m >> Q;
  vector<vector<int>>p(n+1,vector<int>(n+1));
  rep(i,0,m){
    int L,R;
    cin >> L >> R;
    p[L][R]++;
  }
  rep(i,1,n+1) rep(j,1,n+1) p[i][j] += p[i][j-1];
  rep(i,1,n+1) rep(j,1,n+1) p[i][j] += p[i-1][j];
  rep(i,0,Q){
    int L,R;
    cin >> L >> R;
    cout << p[R][R]+p[L-1][L-1]-p[R][L-1]-p[L-1][R] << endl;
  }
}