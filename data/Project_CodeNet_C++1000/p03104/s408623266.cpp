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
int slv(int n){
  int m=n/4*4;
  int res=0;
  for(int i=m;i<=n;i++)res^=i;
  return res;
}
        
signed main(){
  int a,b;
  cin>>a>>b;
  cout<<(slv(b)^slv(a-1))<<endl;
  return 0;
}