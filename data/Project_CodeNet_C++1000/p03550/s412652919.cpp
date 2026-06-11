#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

ll gcd(ll a, ll b){
  return (b ? gcd(b,a%b) : a);
}

int main(){
  int n,z,w; cin >> n >> z >> w;
  vi a(n); rep(i, n) cin >> a[i];

  int ans = abs(w-a[n-1]);
  if(n>1) ans = max(ans, abs(a[n-1] - a[n-2]));

  std::cout << ans << '\n';
}
