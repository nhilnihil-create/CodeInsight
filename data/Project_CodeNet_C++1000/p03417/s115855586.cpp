#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ll n, m;
  cin >> n >> m;
  if(n==1 && m==1) cout << 1 << endl;
  else if(n==1) cout << m-2 << endl;
  else if(m==1) cout << n-2 << endl;
  else cout << (n-2)*(m-2) << endl;
  return 0;
}