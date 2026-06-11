#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string p,q,r;
  cin >> n >> p >> q >> r;
  int ans = 0;
  for(int i = 0; i < n; i++){
    if((p[i] == q[i] && p[i] != r[i]) || (p[i] == r[i] && p[i] != q[i]) || (q[i] == r[i] && p[i] != q[i])) ans++;
    else if(p[i] != q[i] && q[i] != r[i] && p[i] != r[i]) ans += 2;
  }
  cout << ans << endl;
}