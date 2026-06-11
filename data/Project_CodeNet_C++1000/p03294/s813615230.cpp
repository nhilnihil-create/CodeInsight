#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
#include <map>
using namespace std;
typedef long long ll;
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
  int n,x;
  ll ans=0;
  cin >> n;
  rep(i,n){
    cin >> x;
    ans += x-1;
  }
  cout << ans << endl;
  return 0;
}