#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const ll INF = 1001001001;

int main(){
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> B(m);
  vector<vector<int>> A(n,vector<int>(m));
  rep(i,m)cin >> B[i];
  rep(i,n)rep(j,m)cin >> A[i][j];
  ll cnt = 0;
  int tot = 0;
  rep(i,n){
    cnt = 0;
    rep(j,m){
    cnt += A[i][j]*B[j];
  }
  cnt += c;
  if(cnt>0)tot++;
}
cout << tot << endl;
return 0;  
}
