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
  int n; cin >>n;
  vector<int> a(n);
  set<int> A;
  rep(i,n){
    cin >>a[i];
    A.insert(a[i]);
  }
  vector<ll> v;
  for(auto x:A)v.push_back(x);
  sort(all(v));
  map<int,int> mp;
  rep(i,n) mp[a[i]]++;
  int sum=0;
  rep(i,v.size()){
    if(mp[v[i]]<v[i])sum+=mp[v[i]];
    if(mp[v[i]]>v[i])sum+=mp[v[i]]-v[i];
  }
  cout <<sum<<endl;
}

