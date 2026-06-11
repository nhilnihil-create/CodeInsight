#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
#define rrep(i,n) for(int i=1; i<=(n); ++i)
#define drep(i,n) for(int i=(n)-1; i>=0; --i)
#define foreach(it, v) for(typeof(v.begin()) it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second

typedef unsigned int uint;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef set<int> si;

string s;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> s;
  int l = sz(s);
  if (s[0] == '0' || s[l-1] == '1') {
    cout << "-1\n";
    return 0;
  }
  rep(i,l/2){
    if (s[i] != s[l-2-i]) {
      cout << "-1\n";
      return 0;
    }
  }
  int bef = 1;
  rep(i,l-1) {
    cout << bef << " " << (i+2) << "\n";
    if (s[i] == '1') {
      bef = i+2;
    }
  }
  return 0;
}
