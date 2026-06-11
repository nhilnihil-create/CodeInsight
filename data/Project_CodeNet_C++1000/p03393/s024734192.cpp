#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T&a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T&a,T b){if(a>b){a=b;return 1;}return 0;}
const long long mod = 1000000007;
typedef long long ll;

int n,h;
string s,t;

int main() {
  cin >> s;
  if(s.size()<26){
    for(char c='a';c<='z';c++)if(!count(all(s),c)){
      cout << s+c << endl;
      return 0;
    }
  }else{
    bool ok=false;
    rep(i,s.size()-1)if(s[i]<s[i+1]) ok=true; 
    if(!ok)
    cout << -1 << endl;
    else{
      string t=s;
      next_permutation(all(s));
      rep(i,s.size()){
        cout << s[i];
        if(s[i]!=t[i]) break;
      }
        cout << endl;
    }
  }
}