//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stdio.h>

#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed fixed<<setprecision(14)
using namespace std;
using pii=pair<int,int>;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class T> using MAX_pq = priority_queue<T>;
template <class T> using MIN_pq = priority_queue<T,vector<T>,greater<T>>;
template <class A> inline lol abs(A &a) { return (a < 0 ? -a : a); }
const lol Mod=(1e9)+7;
const lol mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
lol n,m,k,r,q;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >>a[i];
  vector<lol> s(n+1);
  for(int i=1;i<=n;i++){
    s[i]=s[i-1]+a[i-1];
  }
  map<lol,int> mp;
  for(int i=0;i<=n;i++){
    mp[s[i]]++;
  }
  lol ans=0;
  set<lol> st;
  for(int i=0;i<=n;i++){
    if(st.find(s[i])==st.end()){
      lol w=mp[s[i]];
      ans+=w*(w-1)/2;
      st.insert(s[i]);
    }
  }
  cout <<ans<<'\n';
  return (0);
}
