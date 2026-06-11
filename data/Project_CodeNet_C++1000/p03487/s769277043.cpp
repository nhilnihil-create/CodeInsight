#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n; cin >>n;
  map<int, int> mp;
  vector<int> a(n);
  rep(i,n) {
    cin >>a[i];
    mp[a[i]]++;
  }
  int cnt = 0;
  for(int x : a){
    if(mp[x]>x){
      cnt += mp[x]-x;
      mp[x] = x;
    }
    if(mp[x]<x){
      cnt += mp[x];
      mp[x] = x;
    }
  }
  cout << cnt << endl;
  return 0;
}