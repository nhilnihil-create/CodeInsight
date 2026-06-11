#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  if(k==0){
    cout << n*n << endl;
    return 0;
  }
  for(int b=1; b<=n; b++){
    ll p = n / b;
    ll q = n % b;
    ans += p * max(0LL, b-k);
    ans += max(0LL, q-k+1);
  }
  cout << ans << endl;
  return 0;
}
