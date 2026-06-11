#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll gcd(ll i,ll j){
  if(i<j){
    swap(i, j);
  }
  if(j==0)return i;
  ll r=i%j;
  while(r!=0){
    i=j;
    j=r;
    r=i%j;
  }
  return j;
}


int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n){
    cin >> a[i];
  }
  vector<ll> g1(n+1);
  g1[1]=a[0];
  repo(i, n-1){
    g1[i+1]=gcd(g1[i], a[i]);
  }
  vector<ll> g2(n+1);
  g2[n-1]=a[n-1];
  for(int i=n-2; i>=0; i--){
    g2[i]=gcd(g2[i+1], a[i]);
  }
  ll ans=0;
  repo(i, n){
    ans=max(ans, gcd(g1[i-1], g2[i]));
  }
  cout << ans << endl;
  return 0;
}
