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
  ans = (n/k)*(n/k)*(n/k);
  if(k%2==0){
    if(n%k>=k/2) ans += (n/k+1)*(n/k+1)*(n/k+1);
    else ans += (n/k)*(n/k)*(n/k);
  }
  cout << ans << endl;
  return 0;
}
