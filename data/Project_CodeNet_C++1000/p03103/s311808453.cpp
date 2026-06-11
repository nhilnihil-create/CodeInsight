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


const int MOD=1000000007;
int INF=100100100100100;
P a[100010];
signed main(){
  int n,m;cin>>n>>m;
  rep(i,n)cin>>a[i].F>>a[i].S;
  sort(a,a+n);
  int ans=0;
  rep(i,n){
    if(m<=a[i].S){
      ans+=(a[i].F)*m;
      break;
    }
    else {
      ans+=(a[i].F)*(a[i].S);
      m-=a[i].S;
    }
  }
  cout<<ans<<endl;
  return 0;
}