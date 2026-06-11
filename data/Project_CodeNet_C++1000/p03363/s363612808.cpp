#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll M=100005;
bool isPrime(long long x){
  if(x == 1)return 0;
  for(long long i = 2; i*i <= x; i++) if(x%i == 0) return 0;
  return 1;
}
int main(){
  ll n;cin>>n;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  vector<ll> sum(n);
  sum=a;
  map<ll,ll> cnt;
  rep(i,n-1){
    sum[i+1]+=sum[i];
  }
  rep(i,n){
    cnt[sum[i]]++;
  }
  ll ans=0;
  for(auto p:cnt){
    if(p.first==0){
      ans+=p.second;
    }
    if(p.second>=2){
       ans+=p.second*(p.second-1)/2;
    }
  }
  cout << ans << endl;
}