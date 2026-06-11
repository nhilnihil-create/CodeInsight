#include <iostream>
#include <vector>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
using namespace std;

int main(){
  int n, m, Q;
  cin >> n >> m >> Q;
  vector<vector<int>> sum(n+1, vector<int>(n+1, 0));
  int l, r;
  rep(i, m){
    cin >> l >> r;
    sum[l][r]++;
  }
  rep(i, n)rep2(j, i, n) sum[i+1][j+1] += sum[i+1][j];
  repr(i, n)rep2(j, i, n) sum[i+1][j+1] += sum[(i+2)%(n+1)][j+1];
  
  int p, q;
  rep(i, Q){
    cin >> p >> q;
    cout << sum[p][q] << endl;
  }
  
  return 0;
}