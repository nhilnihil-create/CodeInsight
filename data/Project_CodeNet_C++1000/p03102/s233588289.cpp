#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int n,m,c;
  cin>>n>>m>>c;
  vector<int>b(m);
  rep(i,m)cin>>b[i];
  vector<vector<int>>a(n,vector<int>(m));
  rep(i,n)rep(j,m)cin>>a[i][j];

  int tmp;
  int cnt=0;
  rep(i,n){
    tmp=0;
    rep(j,m){
      tmp+=a[i][j]*b[j];
    }
    if(tmp+c>0)cnt++;
  }

  cout<<cnt<<endl;
    
  return 0;
}
