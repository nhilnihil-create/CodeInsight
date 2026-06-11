#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
  int n; cin >> n;
  vector<int> a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll x=0,y=0;
  rep(i,n){
    if(a[i] > b[i])x += a[i] - b[i];
    else y += (b[i] - a[i])/2;
  }
  cout << (x <= y ? "Yes" : "No") << endl;
}