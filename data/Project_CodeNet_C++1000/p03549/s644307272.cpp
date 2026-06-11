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
  int index = 1;
  rep(i,m){
    index *= 2;
  }
  int ans = (100*(n-m) + 1900*m) * index;
  cout << ans << endl;
}
