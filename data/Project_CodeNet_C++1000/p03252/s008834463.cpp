#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
using namespace std;
using namespace __gnu_pbds;
 
#define debug(s) cerr << #s << " = " << s << '\n'
#define all(v) (v).begin(), (v).end()
#define mem(a,val) memset(a, val, sizeof a)
 
#define ff first
#define ss second
typedef long long ll;
 
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

map<char, char> mp, used;
bool vis[30];

bool ok(char c, char t) {
  if (mp[c] == t || !mp[c]) return true;
  if (mp[c] == c) return false;
  return ok(mp[c], t);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  if (s.size() != t.size()) {
    cout << "No\n";
    return 0;
  }
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (!mp[s[i]] && !used[t[i]]) {
      mp[s[i]] = t[i];
      used[t[i]] = s[i];
    }
    else {
      if (used[t[i]] != s[i]) {
        cout << "No\n";
        return 0;
      }
      else if (mp[s[i]] != t[i]) {
        cout << "No\n";
        return 0;
      }
    }
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    mem(vis, 0);
    if (!ok(mp[c], c)) {
      cout << "No\n";
      return 0;
    } 
  }
  cout << "Yes\n";
}