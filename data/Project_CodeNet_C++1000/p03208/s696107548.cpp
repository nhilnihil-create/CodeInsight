#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll INF=10100000101010101010101010;
int main(){
  ll n,k;cin >> n >> k;
  ll h[n];
  rep(i,n)cin>>h[i];
  sort(h,h+n,greater<int>());
  ll ans=INF;
  for(int i=0;i<n-k+1;i++){
  ans=min(ans,h[i]-h[i+k-1]);
  }
  cout << ans << endl;
}