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
int b[100];
int a[100][100];
signed main(){
  int n,m,c;cin>>n>>m>>c;
  rep(i,m)cin>>b[i];
  rep(i,n)rep(j,m)cin>>a[i][j];
  int ans=0;
  rep(i,n){
    int sum=0;
    rep(j,m)sum+=a[i][j]*b[j];
    sum+=c;
    if(sum>0)ans++;
  }
  cout<<ans<<endl;
  return 0;
}