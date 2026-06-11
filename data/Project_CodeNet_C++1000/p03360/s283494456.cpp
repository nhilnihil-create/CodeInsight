#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n = 3;
  vector<int> a(n); rep(i,n) cin >> a[i];
  int k; cin >> k;

  sort(a.begin(),a.end());
  rep(i,k){
    a[n-1] *= 2;
  }

  int sum = 0;
  rep(i,n) sum+=a[i];

  cout << sum << endl;
  
  return 0;
}
