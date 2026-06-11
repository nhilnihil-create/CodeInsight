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
  vector<string> s(n);
  vector<ll> a(5);
  rep(i,n){
    cin >> s[i];
    if(s[i][0]=='M')a[0]++;
    if(s[i][0]=='A')a[1]++;
    if(s[i][0]=='R')a[2]++;
    if(s[i][0]=='C')a[3]++;
    if(s[i][0]=='H')a[4]++;
  }
  ll sum =0;
  
  for (int tmp = 0; tmp < (1 << 5); tmp++) {
    bitset<5> t(tmp);  // 最大20個なので20ビットのビット列として扱う
 
    // ビット列の1のビットに対応する整数を選んだとみなして総和を求める
    ll key=0;
    ll sub=1;
    for (int i = 0; i < 5; i++) {
      if (t.test(i)) {
        sub*=a[i];
        key++;
      }
    }
    if (key == 3) {
      sum+=sub;
    }
  }
  cout  <<sum<<endl;
}