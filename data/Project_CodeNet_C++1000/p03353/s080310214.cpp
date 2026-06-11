#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

string s;
int k;
set <string> st;

int main() { 

  getline(cin, s);
  cin >> k;

  for (int i = 0; i < sz(s); i++) {
    for (int j = i; j < min(i + 5, sz(s)); j++) {
      string cur = s.substr(i, j - i + 1);
      st.insert(cur);
      if (sz(st) > k) {
        st.erase(*st.rbegin());
      }
    }
  }

  cout << *st.rbegin() << endl;

  return 0;
}
