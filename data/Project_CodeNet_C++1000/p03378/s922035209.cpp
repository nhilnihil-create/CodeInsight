#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
using P = pair<int,int>;
using ivec = vector<int>;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=100100100100100;
const int MAXR=500010;

signed main(){
  int n,m,x;cin>>n>>m>>x;
  int ans=0;
  rep(i,n){
    int po;cin>>po;
    if(po<x)ans++;
  }
  chmin(ans,m-ans);
  cout<<ans<<endl;
  return 0;
}