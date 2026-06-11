#include <bits/stdc++.h>

using namespace std;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 8010;

string s;
int x, y;
vector <int> v;
vector <int> q;
bool okx, oky;
bool fl[N * 2];
bool *vis = fl + N;

void run() {
  cin >> s;
  cin >> x >> y;
  
  v.push_back(0);
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'T') {
      v.push_back(0);
    } else {
      v.back() ++;
    }
  }

  int n = s.length();

  bool first = 1;
  for (int _ = 0; _ < 2; ++_) {
    for (int x = -n; x <= n; ++x) vis[x] = 0;
    vis[0] = 1;
    for (int i = _; i < v.size(); i += 2) {
      q.clear();
      for (int x = -n; x <= n; ++x) if (vis[x]) q.push_back(x), vis[x] = 0;
      debug(q);
      if (first) {
        //right
        for (auto x : q) {
          vis[x + v[i]] = 1;
        }
        first = 0;
      } else {
        for (auto x : q) {
          vis[x + v[i]] = 1;
          vis[x - v[i]] = 1;
        }
      }
    }
    if (_ == 0 && vis[::x] == 1) {
      okx = 1;
    }
    if (_ == 1 && vis[::y] == 1) {
      oky = 1;
    }
  }
  
  puts(okx && oky ? "Yes" : "No");

}

int main() {
  run();
  return 0;
}
