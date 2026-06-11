#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define MAX 1000000007
using namespace std;

int main(void){
  ll n,k;
  cin >> n >> k;

  ll ans = 0;
  for(ll i=k+1;i<=n;i++){
	ans += (i-k)*(n/i);
	if(k <= n%i) ans += n%i-(k-1);
  }

  if(k == 0) ans = n*n; 
  cout << ans << endl;
  return 0;
}
