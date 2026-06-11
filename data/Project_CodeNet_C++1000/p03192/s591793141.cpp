#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  rep(i, 4) {
    if(n % 10 == 2) ans++;
    n /= 10;
  }
  cout << ans << endl;
}