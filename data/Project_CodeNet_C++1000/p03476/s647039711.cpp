#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5;
bool is_prime[N+5];
int d[N+5]; //d[i]=iの最小の素因数  
int main(){
  for(int i = 0; i < N+5; i++) is_prime[i]=true; //エラトステネス
  for(int i = 2; i < N+5; i++){
    if(is_prime[i]) d[i] = i;
    for(int j = i + i; j < N+5; j += i){
      is_prime[j] = false;
      if(is_prime[i] && d[j]==0) d[j] = i;
    }
  }
  int a[N+5] = {0};
  for(int i = 3; i < N+5; i = i+2){
    if(is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
  }
  int s[N+5] = {0};
  for(int i = 0; i < N+5; i++) s[i+1]=s[i]+a[i];
  int q; cin >> q;
  for(int i = 0; i< q; i++){
    int l, r;
    cin >> l >> r;
    int ans = s[r+1]-s[l];
    cout << ans << endl;
  }
  return 0;
}
    