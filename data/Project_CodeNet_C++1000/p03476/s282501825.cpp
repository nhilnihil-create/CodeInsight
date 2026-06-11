#include<bits/stdc++.h>
using namespace std;
vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}
int ans[100005];
int main(){
    auto t = prime_table(100000);
    for(int i=1;i<=100000;i++)ans[i]=ans[i-1]+(t[i]&t[(i+1)/2]);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << ans[r]-ans[l-1] << endl;
    }
}