#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;
typedef vector<int> ivec;

const int MOD=1000000007;
int INF=100100100100100;
int v[100],c[100];
signed main(){
  int ans=0;
  int n;cin>>n;
  rep(i,n){
    cin>>v[i];
  }
  rep(i,n)cin>>c[i];
  rep(i,n)ans+=max((int)0,v[i]-c[i]);
  cout<<ans<<endl;
  return 0;
}
