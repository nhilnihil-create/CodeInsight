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
  int l=0,r=n-1;
  int ans=0;
  while(l<=r){
    if(s[l]==s[r]){
      l++; r--;
    }
    else if(s[l]=='x'){
      l++;
      ans++;
    }
    else if(s[r]=='x'){
      r--;
      ans++;
    }
    else{
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}