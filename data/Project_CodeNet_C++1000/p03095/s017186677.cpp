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

ll cnt[26];

int main(){
  int n; cin >> n;
  string s; cin >> s;
  rep(i,n){
    cnt[s[i]-'a']++;
  }
  ll ans=1;
  rep(i,26){
    ans*=cnt[i]+1;
    ans%=mod;
  }
  ans--;
  if(ans<0) ans+=mod;
  cout << ans << endl;
  
}