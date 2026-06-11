#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  long long h, w;
  cin >> n >> h >> w;
  int ans = 0;
  for(int i = 0; i < n; i++){
    long long a, b;
    cin >> a >> b;
    if(a >= h && b >= w) ans++;
  }
  cout << ans << endl;
  return 0;
}