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
  string s; cin >> s;
  int n=s.size();
  int BCcnt=0;
  ll ans=0;
  for(int i=n-1;i>=0;i--){
    if(i-1>=0&&s[i]=='C'&&s[i-1]=='B'){
      BCcnt++;
      i--;
    }
    else if(s[i]=='A'){
      ans+=BCcnt;
    }
    else{
      BCcnt=0;
    }
  }
  cout << ans << endl;
  
}