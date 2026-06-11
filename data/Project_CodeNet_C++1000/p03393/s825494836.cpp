#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>

using namespace std;
using ll = long long int;

// void dfs(string now, bitset<26> used) {
//   if (used.count() == 26) {
//     return;
//   }

//   for (size_t i = 0; i < 26; i++) {
//     if (used[i] == 0) {
//       string next = now;
//       char c = ('a' + i);
//       dfs(next + c, (used | bitset<26>(1 << i)));
//       mp[next + c]++;
//     }
//   }
//   return;
// }

int main() {
  string s;
  cin >> s;

  map<char, int> mp;
  for (size_t i = 0; i < s.size(); i++) {
    mp[s[i]]++;
  }

  char remain = '-';
  for (size_t i = 0; i < 26; i++) {
    if (mp['a' + i] == 0) {
      remain = 'a' + i;
      break;
    }
  }

  bool saidai = true;
  for (size_t i = 0; i < 25; i++) {
        if (s[i] < s[i + 1]) {
          saidai = false;
        }
  }

  if (remain != '-') {
    cout << (s + remain) << endl;
  } else if (saidai) {
    cout << -1 << endl;
  } else {
    string next = s;
    next_permutation(next.begin(), next.end());
    string ans;
    for (size_t i = 0; i < 26; i++)
    {
        if (s[i] == next[i]) {
            ans.push_back(s[i]);
        } else {
            ans.push_back(next[i]);
            break;
        }
    }
    cout << ans << endl;
    
  }
}