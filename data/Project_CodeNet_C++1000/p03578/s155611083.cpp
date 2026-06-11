#define _GLIBCXX_DEBUG
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long 
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
  int n,m; 
  cin>>n;
  vector<int> d(n);
  rep(i,n)cin >>d[i];
  cin >>m;
  vector<int> t(m);
  rep(i,m)cin >>t[i];
  sort(all(d));
  sort(all(t));
  map<ll,ll> mpd;
  map<ll,ll> mpt;
  rep(i,n) mpd[d[i]]++;
  rep(i,m) mpt[t[i]]++;
  rep(i,m){
    if(mpt[t[i]]>mpd[t[i]]){
      cout <<"NO"<<endl;
      return 0;
    }
  }
  cout <<"YES"<<endl;
}