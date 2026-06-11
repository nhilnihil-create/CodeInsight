#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
int  a[5];
  int k;
  rep(i,5) cin>>a[i];
  cin>>k;
  bool ok=true;
  
 if(a[4]-a[0]>k) ok=false;
  if(ok) cout<<"Yay!"<<endl;
  else cout<<":("<<endl;
}