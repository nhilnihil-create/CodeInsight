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
int a[100010];
signed main(){
  int n,q;cin>>n>>q;
  string s;cin>>s;
  for(int i=1;i<n;i++){
    if(s[i-1]=='A' && s[i]=='C')a[i+1]=a[i]+1;
    else a[i+1]=a[i];
    //cout<<a[i+1]<<endl;
  }
  rep(ima,q){
    int l,r;cin>>l>>r;l--;r--;
    int ans=a[r+1]-a[l];
    if(l>=1 && s[l-1]=='A' && s[l]=='C')ans--;
    cout<<ans<<endl;
  }
  
  return 0;
}