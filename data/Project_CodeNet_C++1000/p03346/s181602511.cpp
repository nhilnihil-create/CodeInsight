#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

int main(){
int n; cin >> n;
vector<int> pos(n+1);
pos[0] = -1;
for( int i = 0; i < n; ++i ){
  int t; cin >> t;
  pos[t] = i;
}
int cnt = 0;
int ans = 0;
for( int k = 1; k <= n; ++k ){
  if( pos[k-1] < pos[k] ) ++cnt;
  else cnt = 1;
  ans = max(ans, cnt);
}
cout << n-ans << endl;
}