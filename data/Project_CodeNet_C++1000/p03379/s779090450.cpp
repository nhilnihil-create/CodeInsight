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
  ll n ; cin >>n;
  vector<ll> x(n);
  vector<ll> X(n);
  rep(i,n) cin >>x[i];
  rep(i,n) X[i]=x[i];
  sort(all(x));
  ll first=x[n/2-1];
  ll second=x[n/2];
  rep(i,n){
    if(X[i]<second)cout << x[n/2]<<endl;
    else cout <<x[n/2-1]<<endl;
  }
  return 0;
}