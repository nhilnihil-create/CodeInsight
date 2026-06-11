#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<string> s(n+1);
  FOR(i,1,n+1) cin>>s[i];
  FOR(i,1,n+1) s[i]=' '+s[i];
  int ans=0;
  rep(b,n){
    vector<string> now(s);
    FOR(i,1,n+1)FOR(j,1,n+1){
      if(j+b<=n) now[i][j]=s[i][j+b];
      else now[i][j]=s[i][j+b-n];
    }
    bool flag=true;
    FOR(i,1,n+1)FOR(j,1,n+1){
      if(now[i][j]!=now[j][i]){
        flag=false;
        break;
      }
    }
    if(flag) ans++;
  }
  cout<<ans*n<<endl;
}