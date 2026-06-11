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
  vector<string> v(n);
  rep(i,n) cin >> v[i];
  int cntAB=0;
  int cntA=0;
  int cntB=0;
  int ans=0;
  rep(i,n){
    string s=v[i];
    rep(j,s.size()-1){
      if(s[j]=='A'&&s[j+1]=='B') ans++;
    }
    if(s[0]=='B'&&s[s.size()-1]=='A') cntAB++;
    else if(s[0]=='B'&&s[s.size()-1]!='A') cntB++;
    else if(s[0]!='B'&&s[s.size()-1]=='A') cntA++;
  }
  if(cntAB==0) ans+=min(cntA,cntB);
  else if(cntA==0&&cntB==0) ans+=cntAB-1;
  else ans+=cntAB-1+min(cntA,cntB)+1;
  cout << ans << endl;
  
}