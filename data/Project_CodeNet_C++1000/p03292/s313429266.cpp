#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  vector<int> a(3); rep(i,3) cin >> a[i];

  int cost = INF;
  cost = min(cost,abs(a[1]-a[0])+abs(a[2]-a[1]));
  cost = min(cost,abs(a[2]-a[0])+abs(a[1]-a[2]));
  cost = min(cost,abs(a[0]-a[1])+abs(a[2]-a[0]));

  cout << cost << endl;
  
  return 0;
}
