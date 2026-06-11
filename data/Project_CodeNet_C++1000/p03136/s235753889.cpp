#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> l(n); rep(i,n) cin >> l[i];

  sort(l.begin(),l.end());
  
  int sum = 0;
  rep(i,n-1) sum+=l[i];

  if(sum>l[n-1]) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
