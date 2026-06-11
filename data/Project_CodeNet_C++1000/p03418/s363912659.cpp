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
  ll n,k; cin >>n>>k;
  ll ans=0;
  rep2(i,k+1,n+1){
    ans+=n/i*(i-k);
    if(n%i>=k){
      if(k!=0)ans+=n%i-k+1;
      else ans+=n%i-k;
    }
  }
  cout<<ans<<endl;
}