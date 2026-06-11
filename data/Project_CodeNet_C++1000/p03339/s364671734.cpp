#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main(){
  int n;string s;cin>>n>>s;
  vector<int> e(n+1,0),w(n+1,0);
  rep(i,n-1)e[i+1]=e[i]+(s[i]=='W');
  rep(i,n-1)w[i+1]=w[i]+(s[n-1-i]=='E');
  int mn=1000000,p;
  rep(i,n){
    p=e[i]+w[n-1-i];
    mn=min(mn,p);
  }
  cout<<mn;
}