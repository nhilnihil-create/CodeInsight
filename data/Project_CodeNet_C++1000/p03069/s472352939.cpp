#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  vector<int> w(n);
  vector<int> ws(n);
  rep(i,n){
    if(s[i]=='#') w[i]=1;
  }
  ws[0]=w[0];
  for(int i=1;i<n;i++){
    ws[i]=ws[i-1]+w[i];
  }
  vector<int> b(n);
  vector<int> bs(n);
  for(int i=n-1;i>=0;i--){
    if(s[i]=='.') b[i]=1;
  }
  bs[n-1]=b[n-1];
  for(int i=n-2;i>=0;i--){
    bs[i]=bs[i+1]+b[i];
  }
  int ans=min(bs[0],ws[n-1]);
  rep(i,n-1){
    chmin(ans,ws[i]+bs[i+1]);
  }
  cout << ans << endl;
}