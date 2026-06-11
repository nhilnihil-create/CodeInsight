#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

string s, t;
int ans;

int main(void) {
  cin >> s;
  for (int i=0; i<(int)s.size(); i++) {
    if(s[i]!='x') t.pb(s[i]);
  }
  bool ok = true;
  for (int i=0; i <=((int)t.size()-1)/2; i++) {
    if (t[i] != t[(int)t.size()-1-i]) ok = false;
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  int l = 0;
  int r = (int)s.size()-1;
  while (l<r) {
    if (s[l]==s[r]) {
      l++; r--;
    } else {
      ans++;
      if (s[l]=='x') l++;
      else r--;
    }
  }
  cout << ans <<endl;
  
    return 0;
}

