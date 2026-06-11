#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
  ll n,k;
  ll res = 0;
  cin >> n >> k;
  if(k==0){
    cout << n*n << endl;
    return 0;
  }
  for(int b = k+1;b <= n;b++){
    res += (n/b) * (b-k);
    if(n%b >= k){
      res += (n%b) - k +1 ;
    }
  }
  cout << res << endl;
  return 0;
}


