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
  string s; cin >>s;
  ll n=s.size();
  vector<ll> vec(n);
  ll ans=0;
  ll key=0;
  ll black=0;
  rep(i,n)if(s[i]=='B')black++;
  rep(i,n){
    if(s[i]=='B'){
      key++;
      ans+=n-black+key-1-i;
    }
  }
  cout <<ans<<endl;
}